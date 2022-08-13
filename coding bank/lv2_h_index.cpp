#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> cit) {
    int n = cit.size();
    int h = 0;
    int cnt = 0;
    int h_max = -1;
    
    while(1){
        for(int i=0; i < n; ++i){
            if(cit[i] >= h){
                ++cnt;//h번 이상 인용된 논문
            }
        }

        if(cnt >= h){
            if(h_max < h){
                h_max = h;
                ++h;
            }
            else break;
        }
        else --h;
        
        cnt = 0;
    }//end while
    
    return h_max;
}
