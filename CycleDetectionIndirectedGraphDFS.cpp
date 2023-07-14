#include <bits/stdc++.h>
using namespace std;

bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, unordered_map<int, list<int>> &adj){
visited[node] = true;
dfsvisited[node] = true;

for(auto neighbour: adj[node]){
    if(!visited[neighbour]){
        bool checkDetected = checkCycleDFS(neighbour, visited, dfsvisited, adj);
        if(checkDetected)
        return true;
    }
    else if(dfsvisited[neighbour]){
        return true;
    }
}
dfsvisited[node] = false;
return false;
}

int main(){
unordered_map<int, list<int>> adj; 

    int nodes;
    std::cout<<"Enter the number of nodes: ";
    cin>>nodes;

    int edges;
    std::cout<<"Enter the number of edges: ";
    cin>>edges;

int direction = 1;
        for(int i = 0;i < edges;i++){
        int u, v;
        cin>>u>>v;
        //creating an undirected Graph
        adj[u].push_back(v);
        if(direction == 0){
        adj[v].push_back(u);
    }
    }

//call dfs for all component 
int flag = 0;
unordered_map<int, bool> visited;
unordered_map<int, bool> dfsvisited;
    for(int i = 1;i <= nodes;i++){
        if(!visited[i]){
            bool cycleFound = checkCycleDFS(i, visited, dfsvisited, adj);
            if(cycleFound){
                cout<<"Cycle is present"<<endl;
                flag = 1;
                break;
            }
        }
    }
if(flag ==0){
  cout<<"Cycle is not present"<<endl;
}

return 0;
}