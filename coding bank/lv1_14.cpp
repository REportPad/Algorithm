#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> ans;
    
    if(n > m){
        int t = n;
        n = m;
        m = t;
    }
    
    //1. GCD
    int gcd = 1;
    int i=2;
    while(m >= i){
        if(n%i == 0 && m%i == 0){
            gcd *= i;
            n /= i;
            m /= i;
        }
        else{
            ++i;
        }
    }
    
    //2. LCD
    int lcd = gcd*n*m;
    ans.push_back(gcd);
    ans.push_back(lcd);
    
    return ans;
}
