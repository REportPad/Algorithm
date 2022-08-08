#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int n = s.size();
    int cnt = 0;
    
    for(int i=0; i < n; ++i){
        if(s[i] == ' '){
            answer += s[i];
            cnt = 0;
        }
        else{
            int u = cnt%2;
            if(u == 0){
                if(s[i] >= 'a'){
                    answer += (s[i] - 32);
                }
                else{
                    answer += s[i];
                }
            }
            else{
                if(s[i] < 'a'){
                    answer += (s[i] + 32);
                }
                else{
                    answer += s[i];
                }
            }
            ++cnt;
        }
    }
    
    return answer;
}
