#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<int> vi;

int solution(vector<int> num, int tar) {
    int n = num.size();
    int sum = 0;
    int cnt = 0;
    int m = pow(2,n);
    vector<vi> v(m, vi(n, -1));
    
    for(int i=1; i < m-1; ++i){
        int j=0;
        int t = i;
        while(t > 0){
            if(t%2 == 1){
              v[i][n-1 - j] = t%2;  
            }
            t /= 2;
            ++j;
        }        
    }    
    for(int i=0; i < n; ++i){
        v[m-1][i] = 1;
    }
    
    for(int j=0; j < m; ++j){
        for(int i=0; i < n; ++i){
            sum += v[j][i]*num[i];
        }
        
        if(sum == tar){
            ++cnt;
        }
        sum = 0;
    }
        
    return cnt;
}
