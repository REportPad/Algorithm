#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int div) {
    vector<int> ans;
    int n = arr.size();
    
    for(int i=0; i < n; ++i){
        if(arr[i]%div == 0){
            ans.push_back(arr[i]);
        }
    }
    
    if(ans.empty()){
        ans.push_back(-1);
    }
    else{
        sort(ans.begin(), ans.end());
    }
    
    return ans;
}
