#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> topK(vector<int>& arr, int k){
    unordered_map<int,int> freq;
    for(int x:arr) freq[x]++;

    vector<pair<int,int>> v;
    for(auto &p:freq) v.push_back({p.second, p.first});

    sort(v.rbegin(), v.rend());
    vector<int> ans;
    for(int i=0;i<k;i++) ans.push_back(v[i].second);
    return ans;
}

int main(){
    vector<int> arr={3,1,4,4,5,2,6,1};
    vector<int> res=topK(arr,2);
    for(int x:res) cout<<x<<" ";
}
