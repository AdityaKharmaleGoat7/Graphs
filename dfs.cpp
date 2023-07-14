#include <bits/stdc++.h>
using namespace std;
int visited[6] {0};
int g[6][6] = {{0,1,0,0,0,0}, //0
               {1,0,1,0,0,0}, //1
               {0,1,0,1,1,0}, //2
               {0,0,1,0,1,1}, //3
               {0,0,1,1,0,0}, //4
               {0,0,0,1,0,0}  //5
               };
               /*
                Graph:
               0-1-2--3-5
                   | /
                    4  
               */
void dfs(int start_node){  
 cout<<start_node<<" ";
 visited[start_node] = 1; 

 for(int j = 0;j < 6;j++){
    if(g[start_node][j] == 1 && !visited[j]){
        dfs(j);
    }
 }
}
int main(){
int start_node = 5;
dfs(start_node);
return 0;
}