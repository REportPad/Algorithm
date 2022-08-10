#include <vector>
#include <iostream>

using namespace std;

bool isPrime(int n){
    if(n == 2 || n == 3 || n == 5) return true;
    if(n%2 == 0) return false;
    
    for(int i=3; i*i <= n; ++i){
        if(n%i == 0){
            return false;
        }
    }
    
    return true;
}

int solution(vector<int> nums) {
    int n = nums.size();
    int i = 0;
    int j = 1;
    int k = 2;
    int sum = 0;
    int cnt = 0;
    
    while(i <= n - 3){
        sum = nums[i] + nums[j] + nums[k];
        //cout << i << ", " << j << ", " << k << ", " << sum << endl;
        if(isPrime(sum)){
            ++cnt;
        }
        
        if(k < n-1){
            ++k;
        }
        else{
            if(j < n - 2){
                ++j;
                k = j+1;
            }
            else{
                if(i < n - 3){
                    ++i;
                    j = i+1;
                    k = j+1;
                }
                else{
                    ++i;
                }
            }
        }
    }
    
    return cnt;
}
