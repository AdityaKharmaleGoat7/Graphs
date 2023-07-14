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

//Here we are taking 4 nodes, so we are maintaining the distance vector  
vector<int> distance(4);

//initialy we declare the distances as INF for each node
for(int i = 0;i < 4;i++)
distance[i] = INT_MAX;

//we are starting with node '0' you can start with any node
int source = 0;
distance[0] = 0;

set<pair<int, int>> st;   //1st int --> distance, 2nd int --> node

st.insert(make_pair(0, source));

while(!st.empty()){
 auto top = *(st.begin());
 int nodeDistance = top.first;
 int topNode= top.second;

 //remove top record now 
 st.erase(st.begin());

    for(auto neighbour: adj[topNode]){
        if(nodeDistance + neighbour.second < distance[neighbour.first]){
            auto record = st.find(make_pair(distance[neighbour.first], neighbour.first));

            //if record found then erase it
            if(record != st.end()){
                st.erase(record);
            }

            //distance update
            distance[neighbour.first] = nodeDistance + neighbour.second;

            //record push in set
            st.insert(make_pair(distance[neighbour.first], neighbour.first));
        }
    }
}

for(auto i: distance){
    cout<<i<<" ";
}

    return 0;
}