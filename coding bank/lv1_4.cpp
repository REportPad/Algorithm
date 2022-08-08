#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {    
    if(arr.size() == 1){
        vector<int> answer;
        answer.push_back(-1);
        return answer;
    }
    
    int idx = -1;
    int minval = 999999;    
    for(int i=0; i < arr.size(); ++i){
        if(arr[i] < minval){
            idx = i;
            minval = arr[i];
        }
    }
    
    arr[idx] = -1;
    vector<int> ret;
    ret.reserve(arr.size()-1);
    for(int i=0; i < arr.size(); ++i){
        if(arr[i] != -1) ret.push_back(arr[i]);
    }
    
    return ret;
}
