#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long solution(int n, vector<int> work) {
    priority_queue<ll> pq;
    int wsize = work.size();
    
    for(int i=0; i < wsize; ++i){
        pq.push(work[i]);
    }
    
    for(int i=0; i < n; ++i){
        if(pq.top() > 0){
            int t = pq.top()-1;
            pq.pop();
            pq.push(t);   
        }
        else return 0;
    }
    
    ll sum = 0;
    for(int i=0; i < wsize; ++i){
        sum += (pq.top()*pq.top());
        pq.pop();
    }
    
    return sum;
}
