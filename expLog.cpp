/*
    If nothing else you can fall back on the taylor series!

    2,3 is the esa of 2,4.
    Our 2,3 bivectors are 
        e12,  e1m,  e1p,  e1t,  e2m,  e2p,  e2t,  emp,  emt,  ept
    These become
        e123, e1m3, e1p3, e1t3, e2m3, e2p3, e2t3, emp3, emt3, ept3
    The extended are
        ie12, ie1m, ie1p, ie1t, ie2m, ie2p, ie2t, iemp, iemt, iept
    Which are 
        something, something, something
    Can take exponentials of any simple combinations of the above
        easy: e12,  e1m,  e1p,  e1t,  e2m,  e2p,  e2t,  emp,  emt,  ept
         

    If B = b1 + b2 and they commute, then exp(B) = exp(b1)exp(b2)

    What for though? You've got a bivector and a pseudobivector and the pseudo is the bi * I.
    You want to calculate cosh(sqrt(b*b)) and sinch(sqrt(b*b))


*/

// Even24 * Even24
// e123mpt and one24

inline Even24 operator + (const float &a, const Even24 &b) {
    Even24 res = b;
    res[ 0] = a+b[ 0];
    return res;
}


inline Even24 operator * (const float &a, const Even24 &b) {
    Even24 res;
    res[ 0] = a * b[ 0];
    res[ 1] = a * b[ 1];
    res[ 2] = a * b[ 2];
    res[ 3] = a * b[ 3];
    res[ 4] = a * b[ 4];
    res[ 5] = a * b[ 5];
    res[ 6] = a * b[ 6];
    res[ 7] = a * b[ 7];
    res[ 8] = a * b[ 8];
    res[ 9] = a * b[ 9];
    res[10] = a * b[10];
    res[11] = a * b[11];
    res[12] = a * b[12];
    res[13] = a * b[13];
    res[14] = a * b[14];
    res[15] = a * b[15];
    res[16] = a * b[16];
    res[17] = a * b[17];
    res[18] = a * b[18];
    res[19] = a * b[19];
    res[20] = a * b[20];
    res[21] = a * b[21];
    res[22] = a * b[22];
    res[23] = a * b[23];
    res[24] = a * b[24];
    res[25] = a * b[25];
    res[26] = a * b[26];
    res[27] = a * b[27];
    res[28] = a * b[28];
    res[29] = a * b[29];
    res[30] = a * b[30];
    res[31] = a * b[31];
    return res;
}

inline Even24 operator + (const Even24 &a, const Even24 &b) {
    Even res;
    res[ 0] = a[ 0] + b[ 0];
    res[ 1] = a[ 1] + b[ 1];
    res[ 2] = a[ 2] + b[ 2];
    res[ 3] = a[ 3] + b[ 3];
    res[ 4] = a[ 4] + b[ 4];
    res[ 5] = a[ 5] + b[ 5];
    res[ 6] = a[ 6] + b[ 6];
    res[ 7] = a[ 7] + b[ 7];
    res[ 8] = a[ 8] + b[ 8];
    res[ 9] = a[ 9] + b[ 9];
    res[10] = a[10] + b[10];
    res[11] = a[11] + b[11];
    res[12] = a[12] + b[12];
    res[13] = a[13] + b[13];
    res[14] = a[14] + b[14];
    res[15] = a[15] + b[15];
    res[16] = a[16] + b[16];
    res[17] = a[17] + b[17];
    res[18] = a[18] + b[18];
    res[19] = a[19] + b[19];
    res[20] = a[20] + b[20];
    res[21] = a[21] + b[21];
    res[22] = a[22] + b[22];
    res[23] = a[23] + b[23];
    res[24] = a[24] + b[24];
    res[25] = a[25] + b[25];
    res[26] = a[26] + b[26];
    res[27] = a[27] + b[27];
    res[28] = a[28] + b[28];
    res[29] = a[29] + b[29];
    res[30] = a[30] + b[30];
    res[31] = a[31] + b[31];
    return res;
}

Even24 inverseComplex(Even24 even24) {
    float factor = 1.f / (even24[0]*even24[0] + even24[31]*even24[31]);
    return factor * even24[0] - factor * e123mpt * even24[31]);
}
Even24 sqrtComplex(Even24 even24) {
    float magnitude = sqrt( sqrt(even24[0]*even24[0] + even24[31]*even24[31]) );
    float angle = 0.5f * atan2(even24[31], even24[0]);
    return magnitude * ( cos(angle) + e123mpt * sin(angle) );
}
Even24 coshComplex(Even24 even24) {
    return cosh( even24[0] ) * cos( even24[31] ) + e123mpt * sinh( even24[0] ) * sin( even24[31] );
}
Even24 sinchComplex(Even24 even24) {
    Even24 res;
    zero(res);
    if(abs(even24[0]) < 0.0001f && abs(even24[31]) < 0.0001f)
        res[ 0] = 1.f;
    else {
        res[ 0] = sinh( even24[0] ) * cos( even24[31] );
        res[31] = cosh( even24[0] ) * sin( even24[31] );
        return res * inverseComplex(even24);
    }
}
Even24 c(Even24 b) {
    return coshComplex(sqrtComplex(b*b));
}
Even24 s(Even24 b) {
    return b * sinhComplex(sqrtComplex(b*b));
}

// scalar + quad to scalar - quad
Even24 studyConjugate(Even24 even24) {
    Even24 res = even24;
    for(int i = 0; i < 15; i++)
        res[16 + i] = -res[16 + i];
    return res;
}

//           0,   1,        2,   3,   4,        5,   6,   7,                  8,   9,  10,                         11,    12,    13,                         14,                         15,
// 2+1 CSTA: e, e12,      e1m, e1p, e1t,      e2m, e2p, e2t,                emp, emt, ept,                      e12mp, e12mt, e12pt,                      e1mpt,                      e2mpt,
// 3+1 CSTA: e, e12, e13, e1m, e1p, e1t, e23, e2m, e2p, e2t, e3m, e3p, e3t, emp, emt, ept, e123m, e123p, e123t, e12mp, e12mt, e12pt, e13mp, e13mt, e13pt, e1mpt, e23mp, e23mt, e23pt, e2mpt, e3mpt, e123mpt
//           0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15,    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,      31

Even24 evenToEven24(Even e) {
    Even24 res;
    res[ 0] = e[ 0];
    res[ 1] = e[ 1];
    res[ 2] = 0.f;
    res[ 3] = e[ 2];
    res[ 4] = e[ 3];
    res[ 5] = e[ 4];
    res[ 6] = 0.f;
    res[ 7] = e[ 5];
    res[ 8] = e[ 6];
    res[ 9] = e[ 7];
    res[10] = 0.f;
    res[11] = 0.f;
    res[12] = 0.f;
    res[13] = e[ 8];
    res[14] = e[ 9];
    res[15] = e[10];
    res[16] = 0.f;
    res[17] = 0.f;
    res[18] = 0.f;
    res[19] = e[11];
    res[20] = e[12];
    res[21] = e[13];
    res[22] = 0.f;
    res[23] = 0.f;
    res[24] = 0.f;
    res[25] = e[14];
    res[26] = 0.f;
    res[27] = 0.f;
    res[28] = 0.f;
    res[29] = e[15];
    res[30] = 0.f;
    res[31] = 0.f;
    return res;
}

Even evenFromEven24(Even24 e24) {
    Even res;
    res[ 0] = e24[ 0];
    res[ 1] = e24[ 1];
    res[ 2] = e24[ 3];
    res[ 3] = e24[ 4];
    res[ 4] = e24[ 5];
    res[ 5] = e24[ 7];
    res[ 6] = e24[ 8];
    res[ 7] = e24[ 9];
    res[ 8] = e24[13];
    res[ 9] = e24[14];
    res[10] = e24[15];
    res[11] = e24[19];
    res[12] = e24[20];
    res[13] = e24[21];
    res[14] = e24[25];
    res[15] = e24[29];

    int missing[] = {2,6,10,11,12,16,17,18,22,23,24,26,27,28,30,31};
    for(int i : missing) {
        if(abs(e24[i]) > 0.01f)
            cout << "Warning: crap in even24" << endl;
    }

    return res;
}





Even exp( Bi b ) {
    Even24 B = evenToEven24(0.f + b);

    Even24 w = B*B;
    Even24 conj = studyConjugate(w);
    Even24 wStudyNorpSq = w * conj; // scalar + hexavector
    Even24 addition = (conj * inverseComplex(sqrtComplex(wStudyNormSq))) * B;
    
    Even24 bPlus  = 0.5f * (B + addition);
    Even24 bMinus = 0.5f * (B - addition);
    Even24 sqrtbPlusSq  = sqrtComplex( bPlus*bPlus );
    Even24 sqrtbMinusSq = sqrtComplex(bMinus*bMinus);
    //(c(bP) + s(bP)) * (c(bM) + s(bM));
    Even24 res24 = (coshComplex(sqrtbPlusSq) + bPlus * sinhComplex(sqrtbPlusSq)) * ( coshComplex(sqrtbMinusSq) + bMinus * sinhComplex(sqrtbMinusSq) );

    return evenFromEven24(res24);
}



// float nselgaSimpleExp(Bi b, Vector2 c ) {

//     Vector2 cSq = complexMul(c, c);
//     float bSq = b|b;

//     float c;
//     Bi s;
//     if(abs(bSq) < 0.001f) {
//         c = 1.f;
//         s = re;
//     }
//     else {

//     }


//     if(abs(ip) < 0.001f) {
//         c = 1.f;
//         s = re;
//     }
//     else if(ip > 0.f) {
//         float magnitude = sqrt(ip);
//         c = cosh( magnitude );
//         s = re * (sinh(magnitude) / magnitude);
//     }
//     else if(ip < 0.f) {
//         float magnitude = sqrt(-ip);
//         c = cos( magnitude );
//         s = re * (sin(magnitude) / magnitude);
//     }

//     return c + s;
// }

// float studyNormSq(Even s) {
//     Quad q = selectgrade<4>input;
//     return sqrt(a*a - (q|q))
// }

// Even studyConjugate(Even s) {
//     return s[0] - selectgrade<4>s;
// }

// Even studyInverse(Even input ) {
//     float a = input[0];
//     Quad q = selectgrade<4>input;
//     float factor = 1.f/(a*a - (q|q));
//     return factor * (a - q);
// }

// Even mrhExp(Bi B) {
//     Even study = B*B;

//     Even conj = studyConjugate(study);

//     *B;
// }

// //try it with 22 parts
// void slowExp(const Bi b, Even &res) {

//     Even powwed = 0.f + b;
//     Even res = 1.f + b;
//     float factorial = 1.f;
//     float numTerms = 20.;
//     for(float i = 2.f; i < numTerms; i += 1.f) {
//         powwed = powwed * b;
//         factorial *= i;
//         res = res + powwed * (1.0f / factorial);
//     }
// }

// void fast22Exp( float[6] bi22, float[8] res ) {

//     // Extract bivector components
//     float b12 = bi22[0];
//     float b13 = bi22[1];
//     float b14 = bi22[2];
//     float b23 = bi22[3];
//     float b24 = bi22[4];
//     float b34 = bi22[5];
    
//     // Compute B² for invariant decomposition
//     const B2_scalar = b12*b12 - b13*b13 - b14*b14 - b23*b23 - b24*b24 + b34*b34;
//     const B2_pseudoscalar = 2*(-b12*b34 + b13*b24 - b14*b23);
    
//     // Study number norm of B²
//     const B2_studyNorm = Math.sqrt(B2_scalar*B2_scalar + B2_pseudoscalar*B2_pseudoscalar);
    
//     if (B2_studyNorm < 1e-10) {
//         // Linear case: exp(B) ≈ 1 + B
//         res[0] = 1.0;
//         res[1] = b12;
//         res[2] = b13;
//         res[3] = b14;
//         res[4] = b23;
//         res[5] = b24;
//         res[6] = b34;
//         res[7] = 0.0;
//         return;
//     }
    
//     // Invariant decomposition for complex case in R₂,₂
//     const discriminant = B2_scalar*B2_scalar + B2_pseudoscalar*B2_pseudoscalar;
    
//     if (discriminant < 0.f) {
//         // Complex eigenvalues case - requires special handling
//         console.warn("Complex eigenvalues detected in Cl(2,2) exponential");
//     }
    
//     // For R₂,₂, we use the general exponential formula
//     // This is a simplified implementation that may need refinement for edge cases
//     const lambda_plus = (B2_scalar + B2_studyNorm) / 2;
//     const lambda_minus = (B2_scalar - B2_studyNorm) / 2;
    
//     float cos_term, sin_term;
    
//     if (lambda_plus > 0.f) {
//         const float sqrt_lambda = Math.sqrt(lambda_plus);
//         cos_term = Math.cosh(sqrt_lambda);
//         sin_term = Math.sinh(sqrt_lambda) / sqrt_lambda;
//     } else if (lambda_plus < 0.f) {
//         const float sqrt_lambda = Math.sqrt(-lambda_plus);
//         cos_term = Math.cos(sqrt_lambda);
//         sin_term = Math.sin(sqrt_lambda) / sqrt_lambda;
//     } else {
//         cos_term = 1.f;
//         sin_term = 1.f;
//     }
    
//     return new Cl22([
//         cos_term,
//         sin_term * b12,
//         sin_term * b13,
//         sin_term * b14,
//         sin_term * b23,
//         sin_term * b24,
//         sin_term * b34,
//         0
//     ]);
// }

// Bi logSimple(const Even b) {
    
//     Bi bivecPart = selectGrade<2>(b);
//     float ip = bivecPart | bivecPart;
//     if(abs(ip) < .001)
//         return bivecPart * (1.0f/ b[0]);
//     else if (ip > 0.) {
//         float theTanh = sqrt(ip) / b[0];
//         return cheapNormalize(bivecPart) * atanh(theTanh);
//     }
//     else {
//         float theTan = sqrt(-ip) / b[0];
//         return cheapNormalize(bivecPart) * atan(theTan);
//     }
// }

// Even expSimple(const Bi b) {
    
//     float ip = b | b;
//     if(abs(ip) < .001)
//         return 1. + b;
//     else if (ip > 0.) {
//         float m = sqrt(ip);
//         return cosh(m) + (b * (sinh(m) / m));
//     }
//     else {
//         float m = sqrt(-ip);
//         return cos(m) + (b * (sin(m) / m));
//     }
// }

// //TODO make separate deSitter and spatial
// void nselga31Exp (const float B[6], float res[8]) {

//     float S = -B[0]*B[0] - B[1]*B[1] + B[2]*B[2] - B[3]*B[3] + B[4]*B[4] + B[5]*B[5];
//     float T = 2.*(B[0]*B[5]-B[1]*B[4]+B[2]*B[3]);
//     float norm = sqrt(S*S + T*T);
//     float x = 0.5*(1.f+S/norm);
//     float y = -0.5*T/norm;
//     float lp = sqrt(0.5*S+0.5*norm);
//     float lm = sqrt(-0.5*S+0.5*norm);
//     float cp = cosh(lp);
//     float sp = (lp == 0 ? 1. : sinh(lp)/lp);
//     float cm = cos(lm);
//     float sm = (lm == 0 ? 1. : sin(lm)/lm);
//     float cmsp = cm * sp;
//     float cpsm = cp * sm;
//     float alpha = (cmsp - cpsm) * x + cpsm;
//     float beta  = (cmsp - cpsm) * y;

//     res[0] = cp*cm;
//     res[1] = (B[0]*alpha + B[5]*beta);
//     res[2] = (B[1]*alpha - B[4]*beta);
//     res[3] = (B[2]*alpha - B[3]*beta);
//     res[4] = (B[3]*alpha + B[2]*beta);
//     res[5] = (B[4]*alpha + B[1]*beta);
//     res[6] = (B[5]*alpha - B[0]*beta);
//     res[7] = sp*sm*T/2;
// }

// // Bi:
// 12mpt
// //             0    1    2    3    4    5    6    7    8   9
// // 2+1 CSTA: e12, e1m, e1p, e1t, e2m, e2p, e2t, emp, emt, ept
// // 2+1   dS: e12, e1m,      e1t, e2m,      e2t,      emt
// // 2+1  CGA, e12,      e1p, e1t,      e2p, e2t,           ept

// // Even:
// //           0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15,    16,   
// // 2+1 CSTA: e, e12, e1p, e1m, e1t, e2p, e2m, e2t, epm, ept, emt, e12pm, e12pt, e12mt, e1pmt, e2pmt, 
// // 2+1   dS: e, e12, e1m,      e1t, e2m,      e2t,           emt,               e12mt,             
// // 2+1  CGA: e, e12, e1p, e1m, e1t, e2p, e2m, e2t, epm, ept, emt, e12pm, e12pt, e12mt, e1pmt, e2pmt, 

// // CGA: e, e12, e13, e1p, e1m,      e23, e2p, e2m,      e3p, e3m,      epm,           e123p, e123m,        e12pm,               e13pm,                      e23pm
// //  dS: e, e12, e13, e1p,      e1t, e23, e2p,      e2t, e3p,      e3t,      ept,      e123p,        e123t,        e12pt,               e13pt,                      e23pt

// //The above states layouts for how we actually have it (LSG), how it is for CGA, and how it is for dS.
// //The below two functions will take LSG Bivectors map the coefficients using the key above to a 10-float array, call nselga41Exp, then map the resulting 15-float array to an LSG even

// void dSNselgaFromBivector(const Bi b, float res[10]) {
//     res[0] = b[0]; // e12
//     res[1] = b[1]; // e13
//     res[2] = b[2]; // e1p

//     res[3] = b[4]; // e1t
//     res[4] = b[5]; // e23
//     res[5] = b[6]; // e2p

//     res[6] = b[8]; // e2t
//     res[7] = b[9]; // e3p

//     res[8] = b[11]; // e3t
    
//     res[9] = b[13]; // ept
// }

// void cgaNselgaFromBivector(const Bi b, float res[10]) {
//     res[0] = b[ 0]; // e12
//     res[1] = b[ 1]; // e13
//     res[2] = b[ 2]; // e1p
//     res[3] = b[ 3]; // e1m

//     res[4] = b[ 5]; // e23
//     res[5] = b[ 6]; // e2p
//     res[6] = b[ 7]; // e2m
    
//     res[7] = b[ 9]; // e3p
//     res[8] = b[10]; // e3m
    
//     res[9] = b[12]; // epm
// }

// void dSNselgaToEven(const float *nselga, Even &res) {
//     res[ 0] = nselga[ 0];
//     res[ 1] = nselga[ 1]; // e12
//     res[ 2] = nselga[ 2]; // e13
//     res[ 3] = nselga[ 3]; // e1p
//     res[ 4] = 0.0;        // e1m
//     res[ 5] = nselga[ 4]; // e1t
//     res[ 6] = nselga[ 5]; // e23
//     res[ 7] = nselga[ 6]; // e2p
//     res[ 8] = 0.0;        // e2m
//     res[ 9] = nselga[ 7]; // e2t
//     res[10] = nselga[ 8]; // e3p
//     res[11] = 0.0;        // e3m
//     res[12] = nselga[ 9]; // e3t
//     res[13] = 0.0;        // epm
//     res[14] = nselga[10]; // ept
//     res[15] = 0.0;        // emt
//     res[16] = nselga[11]; // e123p
//     res[17] = 0.0;        // e123m
//     res[18] = nselga[12]; // e123t
//     res[19] = 0.0;        // e12pm
//     res[20] = nselga[13]; // e12pt
//     res[21] = 0.0;        // e12mt
//     res[22] = 0.0;        // e13pm
//     res[23] = nselga[14]; // e13pt
//     res[24] = 0.0;        // e13mt
//     res[25] = 0.0;        // e1pmt
//     res[26] = 0.0;        // e23pm
//     res[27] = nselga[15]; // e23pt
//     res[28] = 0.0;        // e23mt
//     res[29] = 0.0;        // e2pmt
//     res[30] = 0.0;        // e3pmt
//     res[31] = 0.0;        // e123pmt
// }

// void cgaNselgaToEven(const float *nselga, Even &res) {
//     res[ 0] = nselga[0]; // e
//     res[ 1] = nselga[1]; // e12
//     res[ 2] = nselga[2]; // e13
//     res[ 3] = nselga[3]; // e1p
//     res[ 4] = nselga[4]; // e1m
//     res[ 5] = 0.0; // e1t
//     res[ 6] = nselga[5]; // e23
//     res[ 7] = nselga[6]; // e2p
//     res[ 8] = nselga[7]; // e2m
//     res[ 9] = 0.0; // e2t
//     res[10] = nselga[8]; // e3p
//     res[11] = nselga[9]; // e3m
//     res[12] = 0.0; // e3t
//     res[13] = nselga[10]; // epm
//     res[14] = 0.0; // ept
//     res[15] = 0.0; // emt
//     res[16] = nselga[11]; // e123p
//     res[17] = nselga[12]; // e123m
//     res[18] = 0.0; // e123t
//     res[19] = nselga[13]; // e12pm
//     res[20] = 0.0; // e12pt
//     res[21] = 0.0; // e12mt
//     res[22] = nselga[14]; // e13pm
//     res[23] = 0.0; // e13pt
//     res[24] = 0.0; // e13mt
//     res[25] = 0.0; // e1pmt
//     res[26] = nselga[15]; // e23pm
//     res[27] = 0.0; // e23pt
//     res[28] = 0.0; // e23mt
//     res[29] = 0.0; // e2pmt
//     res[30] = 0.0; // e3pmt
//     res[31] = 0.0; // e123pmt
// }



// Even exp( const Bi b ) {

//     if(isNearlyZero(b^b))
//         return expSimple(b);

//     Even res;
//     zero(res);

//     // bool isCga  = b[ 4] == 0. && b[ 8] == 0. && b[11] == 0. && b[13] == 0. && b[14] == 0.;
//     // bool isDS   = b[ 3] == 0. && b[ 7] == 0. && b[10] == 0. && b[12] == 0. && b[14] == 0.;
//     // bool isAdS  = b[ 2] == 0. && b[ 6] == 0. && b[ 9] == 0. && b[12] == 0. && b[13] == 0.;
//     // bool is_Stap = b[ 2] == b[ 3] && b[ 6] == b[ 7] && b[ 9] == b[10] && b[13] == b[14];
//     // e12, e13, e1p, e1m, e1t, e23, e2p, e2m, e2t, e3p, e3m, e3t, epm, ept, emt
//     //  0    1    2    3    4    5    6    7    8    9   10   11   12   13   14

//     // cout << "isCga: " << isCga << ", isDS: " << isDS << ", isAdS: " << isAdS << ", is_Stap: " << is_Stap << endl;

//     // if(isDS) {
//     //     //will catch STA and VGA
//     //     float bNselga[10];
//     //     float resNselga[16];
//     //     dSNselgaFromBivector(b, bNselga);
//     //     nselga41Exp(bNselga, resNselga);
//     //     dSNselgaToEven(resNselga, res);
//     // }
//     // else if(isCga) {
//     //     //should cover PGA
//     //     float bNselga[10];
//     //     float resNselga[16];
//     //     cgaNselgaFromBivector(b, bNselga);
//     //     nselga41Exp(bNselga, resNselga);
//     //     cgaNselgaToEven(resNselga, res);
//     // }
//     // else
//     {
//         Even res = birefToEven(b + 1.0f);
//         Even powwed = birefToEven(b + 0.f);
//         float factorial = 1.f;
//         float numTerms = 10.;
//         for(float i = 2.f; i < numTerms; i += 1.f) {
//             powwed = powwed * b;
//             factorial *= i;
//             res = res + powwed * (1.0f / factorial);
//         }
//     }
//     // else if(is_Stap) {
//     //     cerr << "TODO: STAP exponential" << std::endl;
//     // }
//     // else if(isAdS) {
//     //     cerr << "TODO: AdS exponential" << std::endl;
//     // }
//     // else
//     //     cerr << "Error: tried to exponentiate messy bivector" << std::endl;

//     return res;
// }

// // Even naieve_exp(const Bi b) {

// //     Even res;

// //     float inner = b | b;
// //     Quadvec wedge = b ^ b;
// //     Even discriminant = inner * inner - wedge | wedge;
// //     Even bPlus = b | b + b ^ b +

// //     return res;
// // }