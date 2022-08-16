#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(a == 1 || b == 1) return 1;
    if(a == b) return a;
    if(a == 0) return b;
    if(b == 0) return a;
    
    if(a > b){
        int t = a;
        a = b;
        b = t;
    }
    
    int r = b%a;
    while(r > 0){
        b = a;
        a = r;
        r = b%a;
    }
    
    return a;
}

int lcm(int a, int b){
    int x = gcd(a,b);
    int ret = a*b/x;
    return ret;
}

int solution(vector<int> arr) {
    int ans = 1;
    int n = arr.size();
    
    ans = lcm(arr[0], arr[1]);
    
    for(int i=2; i < n; ++i){
        ans = lcm(ans, arr[i]);
    }
    
    return ans;
}
