#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    int m2 = arr2[0].size();
    int sum = 0;
    
    vector<vector<int>> v(n1, vector<int>(m2));//n1xm2

    for(int i=0; i < n1; ++i){
        for(int k=0; k < m2; ++k){
            for(int j=0; j < n2; ++j){
                sum += arr1[i][j]*arr2[j][k];
            }
            v[i][k] = sum;
            sum = 0;
        }
    }
    
    return v;
}
