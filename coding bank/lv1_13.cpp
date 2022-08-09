#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s, int n) {
    int m = s.size();
    for(int i=0; i < m-1; ++i){
        for(int j=i+1; j < m; ++j){
            if(s[i][n] > s[j][n]){
                string t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
            else if(s[i][n] == s[j][n] && s[i] > s[j]){
                string t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }
    }
    
    vector<string> vs(s);
    return vs;
}
