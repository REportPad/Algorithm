#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    int n = s.size();
    vector<int> v;
    
    for(int i=0; i < n; ++i){
        if(s[i] != ' '){
            string t = "";
            while(s[i] != ' '){
                t += s[i];
                ++i;
            }
            
            int x = stoi(t);
            v.push_back(x);
        }
    }
    
    sort(v.begin(), v.end());
    string a = to_string(v[0]);
    string b = to_string(v.back());
    string ans = a + ' ' + b;
    return ans;
}
