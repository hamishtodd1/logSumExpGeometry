//why not structs?

class Una : public Multi {
    public:
        float& operator [] (size_t idx) { return el[idx]; }
        const float& operator [] (size_t idx) const { return el[idx]; }

        Una( array<float, UNA_LEN> arr = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f } ) {
            for(int i = 0; i < UNA_LEN; i++)
                el[i] = arr[i];
        }

        // string toString() const override {
        //     return printElementsWithStrings(el, strings_una, e0sUna, UNA_LEN);
        // }

        int getLen() const override { return UNA_LEN; }
        float* getEl() override { return el; }

    float el[UNA_LEN];
};

class Bi : public Multi {
    public:
        float& operator [] (size_t idx) { return el[idx]; }
        const float& operator [] (size_t idx) const { return el[idx]; }
        
        Bi( array<float, BI_LEN> arr = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f } ) {
            for(int i = 0; i < BI_LEN; i++)
                el[i] = arr[i];
        }

        // string toString() const override {
        //     return printElementsWithStrings(el, strings_bi, e0sBi, BI_LEN);
        // }

        int getLen() const override { return BI_LEN; }
        float* getEl() override { return el; }

    float el[BI_LEN];
};

class Tri : public Multi {
    public:
        float& operator [] (size_t idx) { return el[idx]; }
        const float& operator [] (size_t idx) const { return el[idx]; }

        Tri( array<float, TRI_LEN> arr = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f } ) {
            for(int i = 0; i < TRI_LEN; i++)
                el[i] = arr[i];
        }

        // string toString() const override {
        //     return printElementsWithStrings(el, strings_tri, e0sTri, TRI_LEN);
        // }

        int getLen() const override { return TRI_LEN; }
        float* getEl() override { return el; }

    float el[TRI_LEN];
};

class Quad : public Multi {
    public:
        float& operator [] (size_t idx) { return el[idx]; }
        const float& operator [] (size_t idx) const { return el[idx]; }

        Quad( array<float, QUAD_LEN> arr = { 0.f, 0.f, 0.f, 0.f, 0.f } ) {
            for(int i = 0; i < QUAD_LEN; i++)
                el[i] = arr[i];
        }

        // string toString() const override {
        //     return printElementsWithStrings(el, strings_quad, e0sQuad, QUAD_LEN);
        // }

        int getLen() const override { return QUAD_LEN; }
        float* getEl() override { return el; }

    float el[QUAD_LEN];
};

class Pent : public Multi {
    public:
        float& operator [] (size_t idx) { return el[idx]; }
        const float& operator [] (size_t idx) const { return el[idx]; }
        Pent( float a = 0. ) {
            el[ 0] = a;
        }

        // string toString() const override {
        //     return printElementsWithStrings(el, strings_pent, e0sPent, PENT_LEN);
        // }

        int getLen() const override { return PENT_LEN; }
        float* getEl() override { return el; }

    float el[PENT_LEN];
};

class Even : public Multi {
    public:
        float& operator [] (size_t idx) { return el[idx]; }
        const float& operator [] (size_t idx) const { return el[idx]; }

        Even( array<float, EVEN_LEN> arr = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f } ) {
            for(int i = 0; i < EVEN_LEN; i++)
                el[i] = arr[i];
        }

        // string toString() const override {
        //     return printElementsWithStrings(el, strings_even, e0sEven, EVEN_LEN);
        // }

        int getLen() const override { return EVEN_LEN; }
        float* getEl() override { return el; }

    float el[EVEN_LEN];
};

class Odd : public Multi {
    public:
        float& operator [] (size_t idx) { return el[idx]; }
        const float& operator [] (size_t idx) const { return el[idx]; }
        
        Odd( array<float, ODD_LEN> arr = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f } ) {
            for(int i = 0; i < ODD_LEN; i++)
                el[i] = arr[i];
        }

        // string toString() const override {
        //     return printElementsWithStrings(el, strings_odd, e0sOdd, ODD_LEN);
        // }

        int getLen() const override { return ODD_LEN; }
        float* getEl() override { return el; }

    float el[ODD_LEN];
};



template <int Grade> struct GradeTraits {};
template <> struct GradeTraits<0> { using kVecType = float; };
template <> struct GradeTraits<1> { using kVecType = Una; };
template <> struct GradeTraits<2> { using kVecType = Bi;  };
template <> struct GradeTraits<3> { using kVecType = Tri; };
template <> struct GradeTraits<4> { using kVecType = Quad;  };
template <> struct GradeTraits<5> { using kVecType = Pent; };

const unsigned int Even_grades[] = {
        0,
        2,2,2,2,2,2,2,2,2,2,
        4,4,4,4,4 };
const unsigned int Odd_grades[] = {
        1,1,1,1,1,
        3,3,3,3,3,3,3,3,3,3,
        5 };

template <int grade>
typename GradeTraits<grade>::kVecType selectGrade(Even t) {
    typename GradeTraits<grade>::kVecType result;

    int index = 0;
    for(int i = 0; i < EVEN_LEN; i++) {
        if(Even_grades[i] == grade)
            result[index++] = t[i];
    }
    return result;
}
template <int grade>
typename GradeTraits<grade>::kVecType selectGrade(Odd t) {
    typename GradeTraits<grade>::kVecType result;

    int index = 0;
    for(int i = 0; i < ODD_LEN; i++) {
        if(Odd_grades[i] == grade)
            result[index++] = t[i];
    }
    return result;
}