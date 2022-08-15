#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vector<int> solution(vector<int> prog, vector<int> spd) {
    int n = prog.size();
    int vidx = 0;
    vi t(n);
    vi v;
    double spd_double = spd[0];
    double prog_double = prog[0];
    double d = (100 - prog_double)/spd_double;
    d = ceil(d);
    t[0] = d;
    v.push_back(1);

    for(int i=1; i < n;++i){
        spd_double = spd[i];
        prog_double = prog[i];
        d = (100 - prog_double)/spd_double;
        t[i] = ceil(d);
 
        if(t[i-1] >= t[i]){
            ++v[vidx];
            t[i] = t[i-1];
        }
        else{
            v.push_back(1);
            vidx++;
        }
    }
    
    return v;
}
