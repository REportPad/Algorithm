#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> ret;
    int cnt[3] = {0,};
    int n = answers.size();
    //cout << "n: " << n << endl;
    
    for(int i=0; i < n; ++i){
        //#1
        if(answers[i] == (i)%5+1){
            ++cnt[0];
        }
        
        //#2 1 3 4 5, 1 3 5 7, 0 1 2 3
        int j = i/2; 
        if((i%2==0 && answers[i]==2) || 
           (i%2 != 0 && j%4==0 && answers[i] == 1) ||
          (i%2 != 0 && j%4==1 && answers[i] == 3) ||
          (i%2 != 0 && j%4==2 && answers[i] == 4) ||
          (i%2 != 0 && j%4==3 && answers[i] == 5)){
            ++cnt[1];
        }
           
        //#3
        
        //3 1 2 4 5
        //0 1 2 3 4
        if((j%5 == 0 && answers[i] == 3) ||
          (j%5 == 1 && answers[i] == 1) ||
          (j%5 == 2 && answers[i] == 2) ||
          (j%5 == 3 && answers[i] == 4) ||
          (j%5 == 4 && answers[i] == 5)){
            ++cnt[2];
        }
    }//end for
    
    
    //cout << "cnt: " << cnt[0] << ", " << cnt[1] << ", " << cnt[2] << endl;
    //sorting
    int rank[3] = {0,};
    if(cnt[0] >= cnt[1] && cnt[0] >= cnt[2]){
        rank[0] = 1;
        
        if(cnt[1] >= cnt[2]){
            rank[1] = 2;
            rank[2] = 3;
        }
        else{
            rank[1] = 3;
            rank[2] = 2;
        }
    }
    else if(cnt[1] > cnt[0] && cnt[1] >= cnt[2]){
        rank[0] = 2;
        if(cnt[0] >= cnt[2]){
            rank[1] = 1;
            rank[2] = 3;
        }
        else{
            rank[1] = 3;
            rank[2] = 1;
        }
    }
    else{
        rank[0] = 3;
        if(cnt[0] >= cnt[1]){
            rank[1] = 1;
            rank[2] = 2;
        }
        else{
            rank[1] = 2;
            rank[2] = 1;
        }
    }
    
    //cout << "rank: " << rank[0] << ", " << rank[1] << ", " << rank[2] << endl;
    if(cnt[rank[0]-1] > cnt[rank[1]-1]){
        ret.push_back(rank[0]);
    }
    else{
        if(cnt[rank[1]-1] > cnt[rank[2]-1]){
            ret.push_back(rank[0]);
            ret.push_back(rank[1]);
        }
        else{
            ret.push_back(rank[0]);
            ret.push_back(rank[1]);
            ret.push_back(rank[2]);
        }
    }
    
    return ret;
}
