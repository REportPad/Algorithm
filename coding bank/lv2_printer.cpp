#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<int> printer;
    int answer = 0;
    
    for(int i=0; i<priorities.size(); i++)
        printer.push(i);
    
    int maxValue = *max_element(priorities.begin(),priorities.end());
    while(!printer.empty()) {
        int index = printer.front();
        printer.pop();
        
        if(maxValue != priorities[index])
            printer.push(index);
        else {
            answer++;
            if(index == location) return answer;
            priorities[index] = 0;
            maxValue = *max_element(priorities.begin(),priorities.end());
        }
    }
}
