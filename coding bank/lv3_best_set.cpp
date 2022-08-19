#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;

vector<int> solution(int n, int s) {
    if(n > s){
        vi v;
        v.push_back(-1);
        return v;
    }

    vi vv(n, s/n);
    int t = n*(s/n);//3
    if(t == s){
        return vv;
    }

    for(int i=0; i < s-t; ++i){
        vv[n-1 - i]++;
    }
    return vv;    
}
