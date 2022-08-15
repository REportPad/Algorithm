#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int> pq;
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    for(int i=1,j=0; i<k; i++){//1일째부터 k 전날까지 돌며  
        if(i == dates[j]) pq.push(supplies[j++]); //공급받을 수 있는 날이 있다면 일단 받음
        stock--;
        if(stock == 0) { // 공급이 필요할때 가장 효율좋은 놈을 pop
            stock += pq.top(); pq.pop();
            answer++;
        }
    }
    return answer;
}
