#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj){
 visited[node] = 1;
 
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            topoSort(neighbour, visited, s, adj);
        }
    }
    
s.push(node);
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

vector<bool> visited(nodes);
stack<int> s;   
for(int i = 0;i < nodes;i++){
    if(!visited[i]){
        topoSort(i, visited, s, adj);
    }
}
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

for(auto i:ans){
   std::cout<<i<<" ";
}

return 0;
}