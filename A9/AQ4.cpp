#include <iostream>
#include <vector>
using namespace std;

void dfsIsland(vector<vector<int>>& g, int x, int y){
    int m = g.size(), n = g[0].size();
    if(x<0 || y<0 || x>=m || y>=n || g[x][y] == 0) return;
    g[x][y] = 0;

    dfsIsland(g, x+1, y);
    dfsIsland(g, x-1, y);
    dfsIsland(g, x, y+1);
    dfsIsland(g, x, y-1);
}

int countIslands(vector<vector<int>> g){
    int m = g.size(), n = g[0].size();
    int cnt = 0;

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(g[i][j] == 1){
                cnt++;
                dfsIsland(g, i, j);
            }
    return cnt;
}

int main(){
    vector<vector<int>> g={{1,1,0},{0,1,0},{1,0,1}};
    cout << countIslands(g);
}
