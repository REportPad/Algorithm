#include <bits/stdc++.h>
using namespace std;

int ret;

void func(int n){
    if(n == 1){
        ++ret;
        return;
    }
    
    if(n%2 == 0){
        if(log2(n) == floor(log2(n))){
            n=1;
            func(n);
        }
        else{
            int t = n;
            while(t%2 == 0){
                t /= 2;
            }
            
            ++ret;
            --t;
            func(t);
        }
    }//end if
    else{
        --n;
        ++ret;
        func(n);
    }   
}

int solution(int n){
    func(n);
    return ret;
}
