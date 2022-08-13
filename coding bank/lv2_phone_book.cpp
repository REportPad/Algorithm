#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(string &a, string &b){
    if(a.size() > b.size()){
        return false;
    }
    else if(a.size() == b.size() && a > b){
        return false;
    }
    
    return true;
}

bool solution(vector<string> book) {
    int n = book.size();
    
    sort(book.begin(), book.end(), comp);    
    
    for(int i=0; i < n-1; ++i){
        int d = book[i].size();
        
        for(int j=i+1; j < n; ++j){
            int x = book[j].size();
            d = book[i].size();
            
            if(d == x){
                if(book[i] == book[j]){
                    return false;
                }
            }
            else{//book[i].size() < book[j].size()
                string s = "";
                for(int k=0; k < d; ++k){
                    s += book[j][k];
                }

                if(book[i] == s){
                    return false;
                }
            }
        }
    }
    
    return true;
}
