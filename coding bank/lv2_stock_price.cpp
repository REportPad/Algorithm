#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> p) {
    int n = p.size();
    vector<int> v;
    int cnt = 0;
    
    for(int i=0; i < n-1; ++i){
        cnt = 0;
        for(int j=i+1; j < n; ++j){
            if(p[i] <= p[j]){
                ++cnt;
            }
            else{
                ++cnt;
                break;
            }
        }
        v.push_back(cnt);
    }
    v.push_back(0);
    return v;
}
