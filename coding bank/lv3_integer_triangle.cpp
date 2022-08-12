#include <string>
#include <vector>

using namespace std;

typedef unsigned long long ull;

#define N 501

int solution(vector<vector<int>> tri) {
    int n = tri.size();
    int m = tri[0].size();
    int sum[N][N] = {0,};
    
    sum[0][0] = tri[0][0];
    
    sum[1][0] = sum[0][0] + tri[1][0];
    sum[1][1] = sum[0][0] + tri[1][1];
    
    int j = 0;
    for(int i=2; i < n; ++i){
        sum[i][0] = sum[i-1][0] + tri[i][0];
        for(j=1; j < i; ++j){
            sum[i][j] = max(sum[i-1][j-1], sum[i-1][j]) + tri[i][j];  
        }
        sum[i][i] = sum[i-1][i-1] + tri[i][i];
    }
    
    int ans = -1;
    for(int i=0; i < n; ++i){
        ans = max(ans, sum[n-1][i]);
    }
    
    return ans;
}
