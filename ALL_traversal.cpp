#include <bits/stdc++.h>
using namespace std;
unordered_map<int, list<int>> adj; 

class graph{
public:
  void addEdge(int u, int v, bool direction){
    //direction = 0 -> undirected Graph
    //direction = 1 -> directed Graph
    //create an edge from u to v
    adj[u].push_back(v);  
    if(direction == 0){
    adj[v].push_back(u);
    }
  }

 void printAdjList(){
    for(auto i:adj){
        cout<<i.first<<"-> ";
        for(auto j:i.second){
            cout<<j<<", ";
        }
        cout<<endl;
    }
  }

  void BFS(int node){
    queue<int> q;
    q.push(node);
    unordered_map<int, bool> visited{false};
    visited[node] = 1;
    vector<int> ans;
    while(!q.empty()){
        int front_Node = q.front();
        q.pop();
        ans.push_back(front_Node);

        for(auto i:adj[front_Node]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
   }
  
  void DFS(int node, unordered_map<int, bool> &visited){
    visited[node] = 1;
    cout<<node<<" ";   
    for(auto i:adj[node]){
      if(!visited[i]){
       DFS(i, visited);
        }
    }
  }
};

int main(){
    int nodes;
    cout<<"Enter the number of nodes: ";
    cin>>nodes;

    int edges;
    cout<<"Enter the number of edges: ";
    cin>>edges;

    graph g;

    for(int i = 0;i < edges;i++){
        int u, v;
        cin>>u>>v;
        //creating an undirected Graph
        g.addEdge(u, v, 0);
    }

    g.printAdjList();

    cout<<"Enter the node from where you want to begin: ";
    int node;
    cin>>node;    
    cout<<"BFS traversal: ";
    g.BFS(node);

    cout<<"Enter the node from where you want to begin: ";
    int node1;
    cin>>node1;
    cout<<"DFS traversal: ";
    unordered_map<int, bool> visited;
    g.DFS(node1, visited);   
    return 0;
}