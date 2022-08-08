#include <string>
#include <vector>

using namespace std;

typedef long long ll;

long long solution(int a, int b) {
    ll sum = 0;
    
    if(a > b){
        int t = a;
        a = b;
        b = t;
    }
    
    for(int i=a; i <= b; ++i){
        sum += i;
    }
    
    return sum;
}
