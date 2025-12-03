#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
using namespace std;

int networkDelay(const vector<vector<int>>& times, int n, int k){
    vector<vector<pair<int,int>>> adj(n+1);
    for(auto &t : times)
        adj[t[0]].push_back({t[1], t[2]});

    vector<int> dist(n+1, INT_MAX);
    dist[k] = 0;

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    pq.push({0,k});

    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d != dist[u]) continue;

        for(auto &p : adj[u]){
            int v = p.first, w = p.second;
            if(dist[v] > d + w){
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] == INT_MAX) return -1;
        ans = max(ans, dist[i]);
    }
    return ans;
}

int main(){
    vector<vector<int>> t = {{2,1,1},{2,3,1},{3,4,1}};
    cout << networkDelay(t, 4, 2);
}
