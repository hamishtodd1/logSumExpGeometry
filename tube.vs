#version 330

// Input vertex attributes
in vec3 vertexPosition;
in vec2 vertexTexCoord;
in vec3 vertexNormal;
in vec4 vertexColor;

// Input uniform values
uniform mat4 mvp;
uniform mat4 matModel;

// Output vertex attributes (to fragment shader)
out vec3 fragPosition;
out vec2 fragTexCoord;
out vec4 fragColor;
out vec3 fragNormal;

// NOTE: Add your custom variables here
uniform float myFloat;

// https://github.com/glslify/glsl-inverse
mat3 inverse(mat3 m)
{
    float a00 = m[0][0], a01 = m[0][1], a02 = m[0][2];
    float a10 = m[1][0], a11 = m[1][1], a12 = m[1][2];
    float a20 = m[2][0], a21 = m[2][1], a22 = m[2][2];

    float b01 = a22*a11 - a12*a21;
    float b11 = -a22*a10 + a12*a20;
    float b21 = a21*a10 - a11*a20;

    float det = a00*b01 + a01*b11 + a02*b21;

    return mat3(b01, (-a22*a01 + a02*a21), (a12*a01 - a02*a11),
                b11, (a22*a00 - a02*a20), (-a12*a00 + a02*a10),
                b21, (-a21*a00 + a01*a20), (a11*a00 - a01*a10))/det;
}

// https://github.com/glslify/glsl-transpose
mat3 transpose(mat3 m)
{
  return mat3(m[0][0], m[1][0], m[2][0],
              m[0][1], m[1][1], m[2][1],
              m[0][2], m[1][2], m[2][2]);
}

vec3 rodriguez(vec3 v, vec3 axis, float angle)  {
    float cosA = cos(angle);
    float sinA = sin(angle);
    return v * cosA + cross(axis, v) * sinA + axis * dot(axis, v) * (1.0 - cosA);
}

void main()
{
    fragColor = vertexColor;

    float angle = atan(vertexPosition.z, vertexPosition.x);
    float thickness = 0.03 * length(vertexPosition.xz);
    float lambda = 0.1 * vertexPosition.y;

    vec3 central = vec3(cosh(lambda), sinh(lambda), 0.0);
    vec3 centralNext = vec3(cosh(lambda + 0.01), sinh(lambda + 0.01), 0.0);

    vec3 axis = normalize(centralNext - central);
    //better: rotate (vertexPosition.x, 0, vertexPosition.z)
    vec3 start = vec3(-axis.y, axis.x, 0.0);

    fragNormal = rodriguez(start, axis, angle);
    vec3 final = central + thickness * fragNormal;

    mat3 normalMatrix = transpose(inverse(mat3(matModel)));
    fragNormal = normalize(normalMatrix*vertexNormal);
    gl_Position = mvp * vec4(final, 1.0);
}