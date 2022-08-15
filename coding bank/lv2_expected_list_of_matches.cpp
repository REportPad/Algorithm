#include <iostream>
#include <cmath>
using namespace std;

int ret;

void func(int n, int a, int b){
    if(n == 2){
        ret = log2(n);
        return;
    } 
    
    if(a <= n/2 && b <= n/2){
        n /= 2;
        func(n,a,b);
    }
    else if(a > n/2 && b > n/2){
        a -= (n/2);
        b -= (n/2);
        n /= 2;
        func(n,a,b);
    }
    else{
        ret = log2(n);
        return;
    }
}

int solution(int n, int a, int b){
    if(a > b){
        int t = a;
        a = b;
        b = t;
    }
    
    func(n,a,b);
    return ret;
}
