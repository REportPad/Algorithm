#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) {
    vector<int> ans;
    
    while(n > 0){
        ans.push_back(n%10);
        n /= 10;
    }
    
    return ans;
}
