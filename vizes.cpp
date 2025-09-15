struct BiViz {
    float mv;
    Color color;
};

struct UnaViz {
    Una mv;
    Color color;
};

static Model hyperbolaModel;
static Model sphereModel;
static Mesh cylinderMesh;

void InitVizes() {
    sphereModel = LoadModelFromMesh( GenMeshSphere(1.0f, 12, 12) );
    sphereModel.materials[0].shader = phongShader;
    
    // hyperbola
    {
        int slices = 12;
        int stacks = 10;

        std::vector<Vector3> vertices;
        std::vector<Vector3> normals;
        std::vector<unsigned short> indices;

        float angleStep = 2.0f * PI / slices;
        float r = 1.0f;

        for (int i = 0; i <= stacks; i++) {
            float y = i;

            for (int j = 0; j <= slices; j++) {
                float angle = j * angleStep;
                float x = r * cosf(angle);
                float z = r * sinf(angle);
                Vector3 v = Vector3{ x, y, z };
                vertices.push_back(v);
                normals.push_back(Vector3Normalize(Vector3{ x,0.f,z }));
            }
        }

        for (int i = 0; i < stacks; i++) {
            for (int j = 0; j < slices; j++) {
                int curr = i * (slices + 1) + j;
                int next = curr + slices + 1;

                indices.push_back(next);
                indices.push_back(curr);
                indices.push_back(curr + 1);

                indices.push_back(next);
                indices.push_back(curr + 1);
                indices.push_back(next + 1);
            }
        }

        cylinderMesh = { 0 };
        cylinderMesh.vertexCount = vertices.size();
        cylinderMesh.triangleCount = indices.size() / 3;

        cylinderMesh.vertices = (float*)MemAlloc(cylinderMesh.vertexCount * 3 * sizeof(float));
        cylinderMesh.normals  = (float*)MemAlloc(cylinderMesh.vertexCount * 3 * sizeof(float));
        cylinderMesh.indices  = (unsigned short*)MemAlloc(indices.size() * sizeof(unsigned short));

        for (int i = 0; i < cylinderMesh.vertexCount; i++) {
            cylinderMesh.vertices[i*3 + 0] = vertices[i].x;
            cylinderMesh.vertices[i*3 + 1] = vertices[i].y;
            cylinderMesh.vertices[i*3 + 2] = vertices[i].z;

            cylinderMesh.normals[i*3 + 0] = normals[i].x;
            cylinderMesh.normals[i*3 + 1] = normals[i].y;
            cylinderMesh.normals[i*3 + 2] = normals[i].z;
        }

        for (int i = 0; i < indices.size(); i++) {
            cylinderMesh.indices[i] = indices[i];
        }

        UploadMesh(&cylinderMesh, false);
    }

    hyperbolaModel = LoadModelFromMesh(cylinderMesh);
    hyperbolaModel.materials[0].shader = tubeShader;

    // now you might WANT to generate the hyperbola vertices!
    // but, what about when you applying a transformation to it?

}

void UnloadVizes() {
    UnloadModel(sphereModel);
    UnloadModel(hyperbolaModel);
}

void Draw(const BiViz& viz) {

    DrawModel( hyperbolaModel, Vector3{0.f,0.f,0.f}, 1.f, viz.color );

    //don't forget the two points! Which should maybe be drawn as light cones
}

float getScaleOfOriginScalor(Even os) {

    float theTanh = os[8] / os[0];
    if(theTanh == 1.f)
        return 0.f;
    else if(theTanh == -1.f)
        return INFINITY;
    else
        return exp(-2.f * atanh(theTanh));
}

Vector3 spToVector3(Bi sp) {
    float x = .5 * (sp[1] + sp[2]); // 10
    float y = .5 * (sp[4] + sp[5]); // 20
    float z = .5 * (sp[8] + sp[9]); // 0t

    return Vector3{x, y, z} / sp[7];
}

void Draw(const UnaViz& viz) {

    // DrawModel( oneSheetModel, Vector3{0.f,0.5f,0.f}, 0.1f, viz.color );
}

void DrawTetVerts() {
    DrawModel( sphereModel, Vector3{ 1.f, 1.f, 1.f}, 0.05f, WHITE );
    DrawModel( sphereModel, Vector3{-1.f, 1.f,-1.f}, 0.05f, WHITE );
    DrawModel( sphereModel, Vector3{-1.f,-1.f, 1.f}, 0.05f, WHITE );
    DrawModel( sphereModel, Vector3{ 1.f,-1.f,-1.f}, 0.05f, WHITE );
}