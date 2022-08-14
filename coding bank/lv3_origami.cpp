#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;

vector<int> solution(int n) {
    vi v;
    v.push_back(0);
    if(n == 1) return v;
    
    v.push_back(0);
    v.push_back(1);
    if(n == 2) return v;
    
    for(int j=0; j < n-2; ++j){
        int cidx = v.size()/2;
        int m = 2*v.size()+1;

        v.push_back(0);
        for(int i=0; i < m/2; ++i){
            if(i != cidx) v.push_back(v[i]);
            else v.push_back(1-v[i]);
        }
    }
    
    return v;
}
