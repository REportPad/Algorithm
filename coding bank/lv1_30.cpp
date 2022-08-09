#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int m = reserve.size();
    int k = lost.size();
    
    vector<int> check(n, 1);
    for(int i=0; i < m; ++i){
        check[reserve[i]-1] += 1;
    }
    
    for(int i=0; i < k; ++i){
        check[lost[i]-1] -= 1;
    }
    
    int ans = 0;
    for(int i=0; i < n; ++i){
        if(check[i] >= 1){
            ++ans;
        }
    }
    
    for(int i=0; i < n; ++i){
        //cout << check[i] << " ";
        if(check[i] == 0){
            if(check[i-1] == 2 && i-1 >= 0){
                check[i] = 1;
                check[i-1] = 1;
                ++ans;
            }
            else if(check[i+1] == 2 && i+1 < n){
                check[i] = 1;
                check[i+1] = 1;
                ++ans;
            }
        }
    }
    
    return ans;
}
