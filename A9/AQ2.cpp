#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

int minCost(const vector<vector<int>>& g){
    int m = g.size(), n = g[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    priority_queue<vector<int>,
                   vector<vector<int>>,
                   greater<vector<int>>> pq;

    dist[0][0] = g[0][0];
    pq.push({g[0][0],0,0});

    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int d = cur[0], x = cur[1], y = cur[2];

        if(x == m-1 && y == n-1) return d;

        for(auto &dr : dirs){
            int nx = x + dr[0], ny = y + dr[1];
            if(nx>=0 && ny>=0 && nx<m && ny<n){
                int nd = d + g[nx][ny];
                if(nd < dist[nx][ny]){
                    dist[nx][ny] = nd;
                    pq.push({nd,nx,ny});
                }
            }
        }
    }
    return dist[m-1][n-1];
}

int main(){
    vector<vector<int>> g={{1,2,3},{4,5,6},{7,8,9}};
    cout << minCost(g);
}
