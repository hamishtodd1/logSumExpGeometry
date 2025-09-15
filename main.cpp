using namespace std;
#include <cstdio> // printf
#include <cmath>
#include <algorithm> // sort
#include <iostream>
#include <sstream>
#include <string>
#include <variant>
#include <vector>  // the good kind
#include <array>
#include <iomanip> // setprecision

#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"

#include "vectorOverloads.cpp"
#include "misc.cpp"

Camera3D camera = {0};
float deltaTime;
int frameCount = 0;
Shader phongShader;
Shader tubeShader;

#define RLIGHTS_IMPLEMENTATION
#include "rlights.h"

#include "ga.cpp"
#include "vizes.cpp"

int main(void)
{
    const int screenWidth = 1204;
    const int screenHeight = 692;

    SetConfigFlags(FLAG_MSAA_4X_HINT);  // Enable Multi Sampling Anti Aliasing 4x (if available)
    InitWindow(screenWidth, screenHeight, "");
    SetWindowPosition(1196, 34);
    SetTargetFPS(60);
    rlDisableBackfaceCulling(); //for eg hyperboloid

    // Define the camera to look into our 3d world
    camera.target = Vector3{ 0.0f, 0.5f, 0.0f };      // Camera looking at point
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type
    float cameraYaw = PI / 5.0f;
    float cameraPitch = -PI / 10.0f;
    float cameraDist = 10.0f;

    bool holdingCamera = false;
    Vector2 mousePos = {0., 0.};
    Vector2 mousePosOld = {0., 0.};

    // Load models and texture

    // Load shader and set up some uniforms
    phongShader = LoadShader("lighting.vs", "fog.fs");
    tubeShader = LoadShader("tube.vs", "fog.fs");
    
    InitVizes();
    
    Vector3 limitsMin = { -2.1f, -2.1f, -2.1f };
    Vector3 limitsMax = {  2.1f,  2.1f,  2.1f };
    
        phongShader.locs[SHADER_LOC_MATRIX_MODEL] =  GetShaderLocation(phongShader, "matModel");
        phongShader.locs[SHADER_LOC_VECTOR_VIEW] =   GetShaderLocation(phongShader, "viewPos");
        tubeShader.locs[SHADER_LOC_MATRIX_MODEL] =  GetShaderLocation(tubeShader, "matModel");
        tubeShader.locs[SHADER_LOC_VECTOR_VIEW] =   GetShaderLocation(tubeShader, "viewPos");

        int limitsMinLocPhong = GetShaderLocation(phongShader, "limitsMin");
        int limitsMaxLocPhong = GetShaderLocation(phongShader, "limitsMax");
        int limitsMinLocTube = GetShaderLocation(tubeShader, "limitsMin");
        int limitsMaxLocTube = GetShaderLocation(tubeShader, "limitsMax");

        // 1 point light
        CreateLight(LIGHT_POINT, Vector3{ 0, 2, 6 }, Vector3Zero(), WHITE, phongShader);
        CreateLight(LIGHT_POINT, Vector3{ 0, 2, 6 }, Vector3Zero(), WHITE, tubeShader);

    BiViz myViz;
    myViz.mv = 1.0f;
    myViz.color = BLUE;

    UnaViz myUViz;
    myUViz.mv = em;
    myUViz.color = YELLOW;

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        deltaTime = GetFrameTime();

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            holdingCamera = false;
        else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            mousePos = GetMousePosition();
            mousePosOld = mousePos;

            holdingCamera = true;
        }

        if (holdingCamera) {
            mousePosOld = mousePos;
            mousePos = GetMousePosition();

            cameraYaw -= (mousePos.x - mousePosOld.x) * 0.01f;
            cameraPitch -= (mousePos.y - mousePosOld.y) * 0.01f;
            cameraPitch = Clamp(cameraPitch, -PI / 2.01f, PI / 2.01f);
        }

        float s = (float)GetMouseWheelMove();
        cameraDist *= 1.0f + s * 0.05f;

        camera.position = Vector3{0.,0.,cameraDist};
        camera.position = Vector3RotateByAxisAngle(camera.position, Vector3{1., 0., 0.}, cameraPitch);
        camera.position = Vector3RotateByAxisAngle(camera.position, Vector3{0., 1., 0.}, cameraYaw);

        Vector2 mousePositionForSpace = GetMousePosition();
        mousePositionForSpace.y *= 2.f;
        mousePositionForSpace.x = (mousePositionForSpace.x - GetScreenWidth() / 2.0f) * 2.f + GetScreenWidth() / 2.0f;
        Ray mouseRayOrdinary = GetMouseRay(mousePositionForSpace, camera);

        // Update the light phongShader with the camera view position
        SetShaderValue(phongShader, phongShader.locs[SHADER_LOC_VECTOR_VIEW], &camera.position.x, SHADER_UNIFORM_VEC3);
        SetShaderValue(phongShader, limitsMinLocPhong, &limitsMin, SHADER_UNIFORM_VEC3);
        SetShaderValue(phongShader, limitsMaxLocPhong, &limitsMax, SHADER_UNIFORM_VEC3);

        SetShaderValue(tubeShader, tubeShader.locs[SHADER_LOC_VECTOR_VIEW], &camera.position.x, SHADER_UNIFORM_VEC3);
        SetShaderValue(tubeShader, limitsMinLocTube, &limitsMin, SHADER_UNIFORM_VEC3);
        SetShaderValue(tubeShader, limitsMaxLocTube, &limitsMax, SHADER_UNIFORM_VEC3);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GRAY);

            BeginMode3D(camera);

                BeginShaderMode(phongShader);

                Draw(myViz);
                Draw(myUViz);

                DrawTetVerts();

                EndShaderMode();

            EndMode3D();

            DrawText(TextFormat("CURRENT FPS: %i", GetFPS()), 10, 10, 20, RAYWHITE);

        EndDrawing();

        ++frameCount;
    }


    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadShader(phongShader);
    UnloadVizes();

    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}