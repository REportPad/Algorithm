#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> num){
    set<int> st;
    int n = num.size();
    int half = n/2;
    for(int i=0; i < n; ++i){
        st.insert(num[i]);        
    }
    
    int stsize = st.size();
    if(stsize <= half){
        return stsize;
    }
    else if(stsize > half){
        return half;
    }
}
