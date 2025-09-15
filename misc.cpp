void getAxisAndDegreesAngleFromZPlane(Vector3 plane, Vector3 &axis, float &angle) {
    Vector3 z = Vector3{0.f, 0.f, 1.f};    
    axis = Vector3Normalize(Vector3CrossProduct(z, plane));
    angle = 180. / PI * acosf(Vector3DotProduct(z, plane) / Vector3Length(plane));
}

float sign(float x) {
    return x < 0. ? -1.0f : (x > 0.0f ? 1.0f : 0.0f);
}

float sq(float x) {
    return x * x;
}

float rando() {
    return static_cast<float>(GetRandomValue(0, 32767)) / 32767.0f;
}

Color colorFromFloats(float r, float g, float b, float a = 1.0f) {
    return Color{static_cast<unsigned char>(255 * r),
                 static_cast<unsigned char>(255 * g),
                 static_cast<unsigned char>(255 * b),
                 static_cast<unsigned char>(255 * a)};
}

// https://bids.github.io/colormap/
static Color viridises[5] = {
    Color{68,3,86,255},
    Color{59,82,139,255},
    Color{33,145,140,255},
    Color{94,201,98,255},
    Color{253,231,37,255}
};
Color viridis(float t) {
    Color c1 = viridises[ static_cast<int>(t * 4) ];
    Color c2 = viridises[ static_cast<int>(t * 4) + 1 ];
    float f = t * 4 - static_cast<int>(t * 4);
    return c2 * f + c1 * (1.0f - f);
}