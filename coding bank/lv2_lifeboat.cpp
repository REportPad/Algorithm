#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> pp, int lim) {
    sort(pp.begin(), pp.end(), greater<>());
    int n = pp.size();
    int sum = 0;
    int cnt = 0;
    vector<int> check(n);
    int left=0, right = n-1;
    for(int i=0; i < n; ++i){
        sum = pp[left] + pp[right];
        if(sum <= lim){
            ++cnt;
            check[left]++;
            check[right]++;
            ++left;
            --right;
        }
        else{
            ++cnt;
            check[left]++;
            ++left;
        }
        
        if(left > right ||(left == right && check[left] == 1) ) return cnt;
    }
    
    return cnt;
}
