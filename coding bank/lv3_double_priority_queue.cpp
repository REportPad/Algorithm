#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vector<int> solution(vector<string> op) {
   int n = op.size();
    vector<int> v;
    
    for(int i=0; i < n; ++i){
        if(op[i][0] == 'I'){
            string t = "";
            for(int j=2; j < op[i].size(); ++j){
                t += op[i][j];
            }
            int x = stoi(t);
            v.push_back(x);
            cout << v.back() << endl;
        }
        else if(op[i][0] == 'D' && !v.empty()){
            if(op[i][2] == '1'){//max erase
                int val = -9999999;
                int idx = -1;
                int vsize = v.size();
                for(int j=0; j < vsize; ++j){
                    if(val < v[j]){
                        val = v[j];
                        idx = j;
                    }
                }
                v.erase(v.begin()+idx);
            }
            else{//min erase 
                int val = 9999999;
                int idx = -1;
                int vsize = v.size();
                for(int j=0; j < vsize; ++j){
                    if(val > v[j]){
                        val = v[j];
                        idx = j;
                    }
                }
               v.erase(v.begin()+idx);
            }
        }//end else if
    }//end for
    
    if(v.empty()){
        v.push_back(0);
        v.push_back(0);
    }
    else if(v.size() == 1){
        int t = v.back();
        v.push_back(t);
        v.push_back(t);
    }
    else if(v.size() >= 2){
        sort(v.begin(), v.end());
        vi v2;
        v2.push_back(v.back());
        v2.push_back(v[0]);
        return v2;
    }
    
    return v;
}
