#include <string>
#include <vector>

using namespace std;

typedef long long ll;

long long solution(int N) {
    ll ans = 0;
    ll f[3] = {1,1,2};
    
    if(N == 1) return 4;
    else if(N == 2) return 2*(1+2);
    
    for(int i=0; i < N-2; ++i){
        f[0] = f[1];
        f[1] = f[2];
        f[2] = f[1] + f[0];
    }
    
    ans = 2*(f[2] + f[1]);
    return ans;
}
