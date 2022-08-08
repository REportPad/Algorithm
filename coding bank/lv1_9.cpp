#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

long long solution(long long n) {
    long long ans = 0;
    vi v;
    
    while(n > 0){
        v.push_back(n%10);
        n /= 10;
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    int vsize = v.size();
    for(int i=0; i < vsize; ++i){
        ans += (v[i]*pow(10, vsize-1 - i));
    }
    
    return ans;
}
