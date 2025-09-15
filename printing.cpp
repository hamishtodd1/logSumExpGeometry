static const string strings_even[EVEN_LEN]   = { "", "e12","e1m","e1p","e1t","e2m","e2p","e2t","emp","emt","ept", "e12mp","e12mt","e12pt","e1mpt","e2mpt" };
static const string strings_bi[    BI_LEN]   = {     "e12","e1m","e1p","e1t","e2m","e2p","e2t","emp","emt","ept"                                          };
static const string strings_quad[QUAD_LEN]   = {                                                                  "e12mp","e12mt","e12pt","e1mpt","e2mpt" };
static const string strings_una[  UNA_LEN]   = { "e1","e2","em","ep","et"                                                                                 };
static const string strings_tri[  TRI_LEN]   = {                           "e12m","e12p","e12t","e1mp","e1mt","e1pt","e2mp","e2mt","e2pt","empt"          };
static const string strings_pent[PENT_LEN]   = {                                                                                                 "e12mpt" };
static const string strings_odd[  ODD_LEN]   = { "e1","e2","em","ep","et", "e12m","e12p","e12t","e1mp","e1mt","e1pt","e2mp","e2mt","e2pt","empt","e12mpt" };
static const vector<int> e0sEven    = {2,5,9,12};
static const vector<int> e0sOdd     = {2,5,9,12};
static const vector<int> e0sUna     = {2};
static const vector<int> e0sBi      = {1,4,8};
static const vector<int> e0sTri     = {0,4};
static const vector<int> e0sQuad    = {1};

bool contains(const std::vector<int>& vec, int target) {
    return find(vec.begin(), vec.end(), target) != vec.end();
}

string printElementsWithStrings(const float elements[], const string strings[], const vector<int> e0s, int len) {

    for(int i = 0; i < len; ++i)
        if(isnan(elements[i]))
            return "NAN";

    stringstream res;
    res << fixed << setprecision(2);
    bool had_one = false;
    int ignore_countdown = -1;
    for(int i = 0; i < len; i++) {

        bool displaye0 = contains(e0s, i) && elements[i] != 0.f && abs(elements[i] - elements[i+1])<.001f;
        if( displaye0 ) {

            if(had_one)
                res << " + ";
            string str = strings[i];

            size_t pos = str.find('m');
            if (pos != std::string::npos)
                str[pos] = '0';

            if (abs(elements[i] - 1.f) > .005f || abs(elements[i] - -1.f) > .005f )
                res << fixed << elements[i];
            else if (abs(elements[i] - -1.f)<.005f)
                res << "-";
            res << str;
            had_one = true;            

            ignore_countdown = 1;
        }

        if(ignore_countdown < 0 && elements[i] != 0.f) {
            if(had_one)
                res << " + ";

            if (abs(elements[i] - 1.f) > .005f || abs(elements[i] - -1.f) > .005f )
                res << fixed << elements[i];
            else if (abs(elements[i] - -1.f)<.005f)
                res << "-";

            res << strings[i];
            had_one = true;
        }

        ignore_countdown--;
    }
    if(!had_one) {
        res << "0";
    }

    return res.str();
}