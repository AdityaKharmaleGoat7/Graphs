#include <bits/stdc++.h>
using namespace std;

int main(){
/*

 1--2----3
    |    |
    4----5-- 6
*/
unordered_map<int, list<int>> adj; 

    int nodes;
   std::cout<<"Enter the number of nodes: ";
    cin>>nodes;

    int edges;
    std::cout<<"Enter the number of edges: ";
    cin>>edges;

int direction = 0;
        for(int i = 0;i < edges;i++){
        int u, v;
        cin>>u>>v;
        //creating an undirected Graph
        adj[u].push_back(v);
        if(direction == 0){
        adj[v].push_back(u);
    }
}
unordered_map<int,bool> visited;
unordered_map<int,int> parent;
queue<int> q;
int src = 1;
parent[src] = -1;
visited[src] = 1;
q.push(src);
int flag=0;

while(!q.empty()){
    int front = q.front();
    q.pop();
    for(auto neighbour: adj[front]){
      if(visited[neighbour] == true && neighbour != parent[front]){
        std::cout<<"Cycle is present"<<endl;
        flag = 1;
        break;
      }
      else if(!visited[neighbour]){
        q.push(neighbour);
        visited[neighbour] = 1;
        parent[neighbour] = front;
      }
    }
    if(flag == 1){
        break;
    } 
}
    if(flag == 0){
        std::cout<<"Cycle is not present"<<endl;
    }

return 0;
}