#include <bits/stdc++.h>
using namespace std;
unordered_map<int, list<pair<int,int>>> adj;  
class Graph{
 public:
    void addEdge(int u, int v, int weight){
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
        p = make_pair(u, weight);
        adj[v].push_back(p);
    }

/*  To print the adjacency list
    void printAdj(){
        for(auto i:adj){
            cout<<i.first<<" ->";
            for(auto j: i.second){
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }
            cout<<endl;
        }
    }
*/
};

int main(){
Graph g;

g.addEdge(0, 1, 5);
g.addEdge(0, 2, 8);
g.addEdge(1, 2, 9);
g.addEdge(1, 3, 2);
g.addEdge(3, 2, 6);
// g.printAdj();

//we are starting with node '0' you can start with any node
int source = 0;

vector<int> key(4);
vector<bool> mst(4);
vector<int> parent(4);


for(int i = 0;i < 4;i++){
    key[i] = INT_MAX;
    mst[i] = false;
    parent[i] = -1;
}

key[source] = 0;
mst[source] = true;
parent[source] = -1;

for(int i = 0;i < 4;i++){
    int mini = INT_MAX;
    int u;

    for(int v = 0;v < 4;v++){
        if(mst[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
        }
    }
    //mark min node as true
    mst[u] = true;

    //check it's adjacent node
    for(auto it: adj[u]){
        int v = it.first;
        int w = it.second;
        if(mst[v] == false && w < key[v]){
            parent[v] = u;
            key[v] = w;
        }
    }
}

vector<pair<pair<int,int>, int>> result;

for(int i = 1;i < 4;i++){
    result.push_back({{parent[i], i}, key[i]});
}

  for (const auto& element : result) {
        cout << "First Pair: (" << element.first.first << ", " << element.first.second << ")";
        cout << ", Second Value: " << element.second << endl;
    }

    return 0;
}