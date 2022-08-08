#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef vector<int> vi;

vector<int> solution(vector<int> arr, vector<vector<int>> cmd) {
    vector<int> ans;
    int row = cmd.size();
    //cout << "row: " << row << endl;
    
    for(int i=0; i < row; ++i){
        vi v;
        for(int j=cmd[i][0]-1; j <= cmd[i][1]-1; ++j){
            v.push_back(arr[j]);
            //cout << v.back() << endl;
        }
        sort(v.begin(), v.end());
        ans.push_back(v[cmd[i][2]-1]);
    }
    
    return ans;
}
