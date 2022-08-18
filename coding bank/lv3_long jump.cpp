#include<bits/stdc++.h>

using namespace std;

#define M 1234567

typedef long long ll;

long long solution(int n) {
    if(n == 1) return 1;//1
    else if(n == 2) return 2;//11, 2
   
    ll f[3] = {1,2,3};
    for(int i=3; i <= n; ++i){
        f[2] = (f[0]%M+f[1]%M)%M;
        f[0] = f[1];
        f[1] = f[2];
    }
    
    return f[2]%M;
}
