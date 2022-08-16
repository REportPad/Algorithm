#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> sc, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;//acesnding
    int n = sc.size();
    for(int i=0; i < n; ++i){
        pq.push(sc[i]);
    }
    
    if(pq.top() >= K) return 0;
    
    int cnt = 0;
    while(!pq.empty()){
        int z = pq.top();
        pq.pop();
        
        if(!pq.empty()){
            z += (pq.top()*2);
            pq.pop();
            ++cnt;
            pq.push(z);
        }

        if(pq.top() >= K) return cnt;
    }
    
    if(pq.empty()) return -1;
    return cnt;
}
