#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define M 1234567

int solution(int n) {
    int f[3] = {0,1,2};
    
    for(int i=1; i < n; ++i){
        f[2] = (f[0] + f[1])%M;
        f[0] = f[1];
        f[1] = f[2];
    }
    
    return f[2];
}
