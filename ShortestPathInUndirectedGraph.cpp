#include <bits/stdc++.h>
using namespace std;

int main(){

/*
    2-----5
   /       \
  1----3----8
   \       /
    4--6--7
*/

int g[9][9] = {{0,0,0,0,0,0,0,0,0},
               {0,0,1,1,1,0,0,0,0},
               {0,1,0,0,0,1,0,0,0},
               {0,1,0,0,0,0,0,0,1},
               {0,1,0,0,0,0,1,0,0},
               {0,0,1,0,0,0,0,0,1},
               {0,0,0,0,1,0,0,1,0},
               {0,0,0,0,0,0,1,0,1},
               {0,0,0,0,1,0,0,1,0}
                };
int visited[9] {0}, parent[9] {0}, src, destination;
cin>>src;
cin>>destination;
visited[src] = 1;
parent[src] = -1;

queue<int> q;
q.push(src);


while(!q.empty()){
    int front = q.front();
    q.pop();

    for(int i = 1;i <= 8;i++){
        if(!visited[i] && g[front][i] == 1){
            visited[i] = 1;
            parent[i] = front;
            q.push(i);
        }
    }
}

//prepare shortest path
vector<int> ans;
ans.push_back(destination);

while(destination != src){ 
    destination = parent[destination];
    ans.push_back(destination);     
}

for(int i = ans.size()-1;i >= 0;i--){
    cout<<ans[i]<<" ";
    ans.pop_back();
}
cout<<endl;

    return 0;
}