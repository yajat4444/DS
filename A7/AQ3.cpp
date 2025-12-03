#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> maxComb(vector<int>& a, vector<int>& b, int k){
    int n=a.size();
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({a[0]+b[0], {0,0}});
    
    vector<vector<int>> used(n, vector<int>(n,0));
    used[0][0]=1;

    vector<int> ans;
    while(k--){
        auto top=pq.top(); pq.pop();
        ans.push_back(top.first);
        int i=top.second.first, j=top.second.second;
        
        if(i+1<n && !used[i+1][j]){
            used[i+1][j]=1;
            pq.push({a[i+1]+b[j], {i+1,j}});
        }
        if(j+1<n && !used[i][j+1]){
            used[i][j+1]=1;
            pq.push({a[i]+b[j+1], {i,j+1}});
        }
    }
    return ans;
}

int main(){
    vector<int>a={1,4,2,3}, b={2,5,1,6};
    vector<int>res=maxComb(a,b,3);
    for(int x:res) cout<<x<<" ";
}
