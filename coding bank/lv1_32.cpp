#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

long long solution(long long n) {
    ll x = sqrt(n);
    if(x*x == n){
        return (x+1)*(x+1);
    }
    else{
        return -1;
    }
}
