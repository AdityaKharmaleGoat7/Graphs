#include <bits/stdc++.h>
using namespace std;
int visited[6] {0};
int g[6][6] = {{0,1,0,0,0,0},
               {1,0,1,0,0,0},
               {0,1,0,1,1,0},
               {0,0,1,0,1,1},
               {0,0,1,1,0,0},
               {0,0,0,1,0,0}
               };
                /*
                Graph:
               0-1-2--3-5
                   | /
                    4 
               */ 

int main(){
vector<int> ans;
queue<int> q;
int src;
src = 5;  
q.push(src);
visited[src] = 1;

while(!q.empty()){
    int frontNode = q.front();
    q.pop();

    //store front node in ans
    ans.push_back(frontNode);

    //traverse all neighbours of frontNode
    for(int i = 0;i < 6;i++){
        if(g[frontNode][i] == 1 && !visited[i]){
            q.push(i);
            visited[i] = 1; 
        }
    }
}

 for(int i = 0;i < ans.size();i++){
    cout<<ans[i]<<" ";
 }


return 0;
}