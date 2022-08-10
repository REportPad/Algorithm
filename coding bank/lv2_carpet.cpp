#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> v;
    
    int r = 0;
    int c = 0;
    int k = brown + yellow;

    for(r = 1; r < brown; ++r){
        if(2*r*r -(4+brown)*r + 2*k == 0){
            c = k/r;
            break;
        }
    }
    
    if(c > r){
        int t = c;
        c = r;
        r = t;
    }
    v.push_back(r);
    v.push_back(c);
    
    return v;
}
