#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> solution(int n, int m){
    vector<string> s(m);
    
    for(int i=0; i < m; ++i){
        for(int j=0; j < n; ++j){
            s[i] += '*';
        }
    }
    
    return s;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<string> s = solution(n, m);
    
    for(int i=0; i < m; ++i){
        cout << s[i] << endl;
    }

    return 0;
}
