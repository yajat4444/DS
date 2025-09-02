
#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> nextWarmerTemp(vector<int> &nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nwarmdays(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            nwarmdays[i] = st.empty() ? 0 : (st.top()-i);
            st.push(i);
        }

        return nwarmdays;
        
    }

    void Display(const vector<int> &nums){
        for(int i=0; i<nums.size(); i++){
            cout<<nums[i]<<"\t";
        }
    }

     int main(){
        vector<int>temperature={2,4,3,1,8,5,9,88};
        
        vector<int>nge=nextWarmerTemp(temperature);

        Display(nge);
        return 0;
     }
