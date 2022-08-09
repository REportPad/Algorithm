#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> v;
    v.push_back(arr[0]);
    
    for(int i=1; i < arr.size(); ++i){
        if(arr[i] == v.back()){
            
        }
        else{
            v.push_back(arr[i]);
        }
    }
    
    return v;
}
