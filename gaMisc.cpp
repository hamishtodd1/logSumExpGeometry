void print(const Multi& mv) { cout << mv.toString() << endl; }
void print(const float m) { printf("%.2f\n", m); }
void print(string str, const Multi& mv) {cout << str << ": " << mv.toString() << endl; }
void print(string str, float  mv) {cout << str << ": " << mv            << endl; }
void printOnce(Multi& mv) { if(frameCount == 1) cout << mv.toString() << endl; }
void printOnce(float  mv) { if(frameCount == 1) cout << mv            << endl; }
void printOnce(string str, Multi& mv) { if(frameCount == 1) cout << str << ": " << mv.toString() << endl; }
void printOnce(string str, float  mv) { if(frameCount == 1) cout << str << ": " << mv            << endl; }

bool isZero(const Una  mv) { for(int i = 0; i < UNA_LEN;  i++) if(mv[i] != 0.0f) return false; return true; }
bool isZero(const Bi   mv) { for(int i = 0; i < BI_LEN;   i++) if(mv[i] != 0.0f) return false; return true; }
bool isZero(const Tri  mv) { for(int i = 0; i < TRI_LEN;  i++) if(mv[i] != 0.0f) return false; return true; }
bool isZero(const Quad mv) { for(int i = 0; i < QUAD_LEN; i++) if(mv[i] != 0.0f) return false; return true; }
bool isZero(const Pent mv) { for(int i = 0; i < PENT_LEN; i++) if(mv[i] != 0.0f) return false; return true; }
bool isZero(const Even mv) { for(int i = 0; i < EVEN_LEN; i++) if(mv[i] != 0.0f) return false; return true; }
bool isZero(const Odd  mv) { for(int i = 0; i < ODD_LEN;  i++) if(mv[i] != 0.0f) return false; return true; }

bool isNearlyZero(const Una  mv) { for(int i = 0; i < UNA_LEN;  i++) if(abs(mv[i]) > 0.001f) return false; return true; }
bool isNearlyZero(const Bi   mv) { for(int i = 0; i < BI_LEN;   i++) if(abs(mv[i]) > 0.001f) return false; return true; }
bool isNearlyZero(const Tri  mv) { for(int i = 0; i < TRI_LEN;  i++) if(abs(mv[i]) > 0.001f) return false; return true; }
bool isNearlyZero(const Quad mv) { for(int i = 0; i < QUAD_LEN; i++) if(abs(mv[i]) > 0.001f) return false; return true; }
bool isNearlyZero(const Pent mv) { for(int i = 0; i < PENT_LEN; i++) if(abs(mv[i]) > 0.001f) return false; return true; }
bool isNearlyZero(const Even mv) { for(int i = 0; i < EVEN_LEN; i++) if(abs(mv[i]) > 0.001f) return false; return true; }
bool isNearlyZero(const Odd  mv) { for(int i = 0; i < ODD_LEN;  i++) if(abs(mv[i]) > 0.001f) return false; return true; }

void zero(Una  &mv) { for(int i = 0; i < UNA_LEN;  i++) mv[i] = 0.0f; }
void zero(Bi   &mv) { for(int i = 0; i < BI_LEN;   i++) mv[i] = 0.0f; }
void zero(Tri  &mv) { for(int i = 0; i < TRI_LEN;  i++) mv[i] = 0.0f; }
void zero(Quad &mv) { for(int i = 0; i < QUAD_LEN; i++) mv[i] = 0.0f; }
void zero(Pent &mv) { for(int i = 0; i < PENT_LEN; i++) mv[i] = 0.0f; }
void zero(Even &mv) { for(int i = 0; i < EVEN_LEN; i++) mv[i] = 0.0f; }
void zero(Odd  &mv) { for(int i = 0; i < ODD_LEN;  i++) mv[i] = 0.0f; }

// "semi" to remind you it is likely to be negative!
float cheapSemiNormSq(Una  x) { return  x | x; }
float cheapSemiNormSq(Bi   x) { return  x | x; }
float cheapSemiNormSq(Tri  x) { return  x | x; }
float cheapSemiNormSq(Quad x) { return  x | x; }
float cheapSemiNormSq(Pent x) { return  x | x; }
float cheapSemiNormSq(Even x) { return (x | (~x))[0]; }
float cheapSemiNormSq(Odd  x) { return (x | (~x))[0]; }

Una  cheapNormalize(Una  mv) { return mv * (1.0f / sqrt( abs( cheapSemiNormSq(mv)))); }
Bi   cheapNormalize(Bi   mv) { return mv * (1.0f / sqrt( abs( cheapSemiNormSq(mv)))); }
Tri  cheapNormalize(Tri  mv) { return mv * (1.0f / sqrt( abs( cheapSemiNormSq(mv)))); }
Quad cheapNormalize(Quad mv) { return mv * (1.0f / sqrt( abs( cheapSemiNormSq(mv)))); }
Pent cheapNormalize(Pent mv) { return mv * (1.0f / sqrt( abs( cheapSemiNormSq(mv)))); }
Even cheapNormalize(Even mv) { return mv * (1.0f / sqrt( abs( cheapSemiNormSq(mv)))); }
Odd  cheapNormalize(Odd  mv) { return mv * (1.0f / sqrt( abs( cheapSemiNormSq(mv)))); }

inline Tri   operator & (const Quad &a, const Quad &b) { return e12mpt | ((e12mpt | a) ^ (e12mpt | b)); }
inline Bi    operator & (const Quad &a, const  Tri &b) { return e12mpt | ((e12mpt | a) ^ (e12mpt | b)); }
inline Una   operator & (const Quad &a, const   Bi &b) { return e12mpt | ((e12mpt | a) ^ (e12mpt | b)); }
inline float operator & (const Quad &a, const  Una &b) { return e12mpt | ((e12mpt | a) ^ (e12mpt | b)); }

inline Bi    operator & (const  Tri &a, const Quad &b) { return e12mpt | ((e12mpt | a) ^ (e12mpt | b)); }
inline Una   operator & (const  Tri &a, const  Tri &b) { return e12mpt | ((e12mpt | a) ^ (e12mpt | b)); }
inline float operator & (const  Tri &a, const   Bi &b) { return e12mpt | ((e12mpt | a) ^ (e12mpt | b)); }

inline Una   operator & (const   Bi &a, const Quad &b) { return e12mpt | ((e12mpt | a) ^ (e12mpt | b)); }
inline float operator & (const   Bi &a, const  Tri &b) { return e12mpt | ((e12mpt | a) ^ (e12mpt | b)); }