#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef unsigned long long ull;

int solution(int num) {
    int ans = 0;
    ull t = num;
    
    while(ans < 500 && t > 1){
        if(t%2 == 0) t /= 2;
        else{
            t = 3*t+1;
        }
        ++ans;
        //cout << ans << ", " << t << endl;
    }
    
    if(ans >= 500) return -1;
    
    return ans;
}
