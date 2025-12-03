#include <iostream>
#include <vector>
using namespace std;

int maxIceCream(vector<int>& cost, int coins){
    int maxC=*max_element(cost.begin(),cost.end());
    vector<int> count(maxC+1,0);

    for(int c:cost) count[c]++;

    int bars=0;
    for(int price=1;price<=maxC;price++){
        if(count[price]==0) continue;
        int canBuy=min(count[price], coins/price);
        bars+=canBuy;
        coins-=canBuy*price;
        if(coins<price) break;
    }
    return bars;
}

int main(){
    vector<int> cost={1,3,2,4,1};
    cout<<maxIceCream(cost,7);
}
