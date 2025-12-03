#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortEvenOdd(vector<int>& arr){
    vector<int> even, odd;
    for(int i=0;i<arr.size();i++){
        if(i%2==0) even.push_back(arr[i]);
        else odd.push_back(arr[i]);
    }
    sort(even.begin(),even.end());
    sort(odd.rbegin(),odd.rend());
    
    vector<int> ans;
    for(int x:even) ans.push_back(x);
    for(int x:odd) ans.push_back(x);
    return ans;
}

int main(){
    vector<int> arr={0,1,2,3,4,5,6,7};
    vector<int> ans=sortEvenOdd(arr);
    for(int x:ans) cout<<x<<" ";
}
