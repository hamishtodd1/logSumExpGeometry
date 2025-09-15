

/////////////
// Vector2 //
/////////////

void print(const Vector2 m) { cout << m.x << ", " << m.y << endl; }
// void printOnce(const Vector2 m) { if(frameCount == 1) cout << m.x << ", " << m.y << endl; }
void print(string str, const Vector2 m) { cout << str << ": " << m.x << ", " << m.y << endl; }
// void printOnce(string str, const Vector2 m) { if(frameCount == 1) cout << str << ": " << m.x << ", " << m.y << endl; }

inline Vector2 operator * (const float &a, const Vector2 &b) {
    return Vector2{ a * b.x, a * b.y };
}

/////////////
// Vector3 //
/////////////

void print(const Vector3 m) { cout << m.x << ", " << m.y << ", " << m.z << endl; }
// void printOnce(const Vector3 m) { if(frameCount == 1) cout << m.x << ", " << m.y << ", " << m.z << endl; }
void print(string str, const Vector3 m) { cout << str << ": " << m.x << ", " << m.y << ", " << m.z << endl; }
// void printOnce(string str, const Vector3 m) { if(frameCount == 1) cout << str << ": " << m.x << ", " << m.y << ", " << m.z << endl; }


inline Vector3 operator * (const float &a, const Vector3 &b) {
    return Vector3{ a * b.x, a * b.y, a * b.z };
}


/////////////
// Vector4 //
/////////////

void print(const Vector4 m) { cout << m.x << ", " << m.y << ", " << m.z << ", " << m.w << endl; }
// void printOnce(const Vector4 m) { if(frameCount == 1) cout << m.x << ", " << m.y << ", " << m.z << ", " << m.w << endl; }
void print(string str, const Vector4 m) { cout << str << ": " << m.x << ", " << m.y << ", " << m.z << ", " << m.w << endl; }
// void printOnce(string str, const Vector4 m) { if(frameCount == 1) cout << str << ": " << m.x << ", " << m.y << ", " << m.z << ", " << m.w << endl; }

inline Vector4 operator * (const float &a, const Vector4 &b) {
    return Vector4{ a * b.x, a * b.y, a * b.z, a * b.w };
}

///////////
// Color //
///////////


inline Color operator * (const Color &a, const float &b) {
    return Color{ 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.r) * b))), 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.g) * b))), 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.b) * b))), 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.a) * b))) 
    };
}

inline Color operator * (const float &a, const Color &b) {
    return Color{ 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(b.r) * a))), 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(b.g) * a))), 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(b.b) * a))), 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(b.a) * a))) 
    };
}

inline Color operator / (const Color &a, const float &b) {
    return Color{ 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.r) / b))), 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.g) / b))), 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.b) / b))), 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.a) / b))) 
    };
}

inline Color operator + (const Color &a, const Color &b) {
    return Color{ 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.r) + static_cast<float>(b.r)))), 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.g) + static_cast<float>(b.g)))), 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.b) + static_cast<float>(b.b)))), 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.a) + static_cast<float>(b.a)))) 
    };
}

inline Color operator - (const Color &a, const Color &b) {
    return Color{ 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.r) - static_cast<float>(b.r)))), 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.g) - static_cast<float>(b.g)))), 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.b) - static_cast<float>(b.b)))), 
        static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.a) - static_cast<float>(b.a)))) 
    };
}

inline Color& operator *= (Color &a, const float &b) {
    a.r = static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.r) * b)));
    a.g = static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.g) * b)));
    a.b = static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.b) * b)));
    a.a = static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.a) * b)));
    return a;
}

inline Color& operator /= (Color &a, const float &b) {
    a.r = static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.r) / b)));
    a.g = static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.g) / b)));
    a.b = static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.b) / b)));
    a.a = static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.a) / b)));
    return a;
}

inline Color& operator += (Color &a, const Color &b) {
    a.r = static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.r) + static_cast<float>(b.r))));
    a.g = static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.g) + static_cast<float>(b.g))));
    a.b = static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.b) + static_cast<float>(b.b))));
    a.a = static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.a) + static_cast<float>(b.a))));
    return a;
}

inline Color& operator -= (Color &a, const Color &b) {
    a.r = static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.r) - static_cast<float>(b.r))));
    a.g = static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.g) - static_cast<float>(b.g))));
    a.b = static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.b) - static_cast<float>(b.b))));
    a.a = static_cast<unsigned char>(min(255.0f, max(0.0f, static_cast<float>(a.a) - static_cast<float>(b.a))));
    return a;
}