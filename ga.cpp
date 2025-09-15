// 1    
// e1       e2      em      ep      et   
// e12      e1m     e1p     e1t     e2m     e2p     e2t     emp     emt     ept   
// e12m     e12p    e12t    e1mp    e1mt    e1pt    e2mp    e2mt    e2pt    empt 
// e12mp    e12mt   e12pt   e1mpt   e2mpt    
// e12mpt


#define UNA_LEN 5
#define BI_LEN 10
#define TRI_LEN 10
#define QUAD_LEN 5
#define PENT_LEN 1
#define ODD_LEN 16
#define EVEN_LEN 16

//since you're writing the function for every class, you don't need the darn "virtual" shit.
class Multi {
public:
    virtual string toString() const { return "";}
    virtual int getLen() const {return -1;}
    virtual float *getEl() = 0;
};

#include "printing.cpp"
#include "classesAndGradeExtractions.cpp"
#include "generated.cpp"
#include "sandwiches.cpp"
#include "builtIns.cpp"
#include "gaMisc.cpp"

// #include "expLog.cpp"
// #include "minkowskiEvent.cpp"
// #include "lsgMisc.cpp"
// #include "drawMisc.cpp"