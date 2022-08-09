#include <string>
#include <vector>

using namespace std;

typedef long long ll;

vector<long long> solution(int x, int n) {
    vector<long long> ans(n);

    ans[0] = x;
    for(ll i =1; i < n; ++i){
        ans[i] = x*(i+1);
    }
    
    return ans;
}
