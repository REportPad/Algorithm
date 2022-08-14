#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());

    int n = A.size();
    int cnt = 0;
    for(int i=0; i < n; ++i){
        if(A.back() >= B[i]){
            A.pop_back();
            --i;
        }
        else if(A.back() < B[i]){
            ++cnt;
            A.pop_back();
        }
        
        if(A.empty()) break;
    }//end for
    
    return cnt;
}
