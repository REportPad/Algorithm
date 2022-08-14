#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;

vector<int> solution(vector<int> h) {
    int n = h.size();
    vi v(n);
    
    for(int i=n-1; i > 0; --i){
        for(int j=i-1; j >= 0; --j){
            if(h[j] > h[i]){
                v[i] = j+1;
                break;
            }
        }
    }
    
    return v;
}
