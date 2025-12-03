#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, const vector<vector<int>>& adj, vector<int>& vis){
    vis[u] = 1;
    for(int v : adj[u])
        if(!vis[v]) dfs(v, adj, vis);
}

int main(){
    int V = 5;
    vector<vector<int>> adj(V);

    vector<pair<int,int>> edges = {{0,1},{1,2},{3,4}};
    for(auto &e : edges){
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }

    vector<int> vis(V, 0);
    int count = 0;

    for(int i = 0; i < V; i++)
        if(!vis[i]){
            count++;
            dfs(i, adj, vis);
        }

    cout << count;
}
