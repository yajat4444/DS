
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;


int priority(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

string Inf2Pof(string &s){
    int n=s.length();
    int i=0;
    stack<char>st;
    string ans="";

    while(i<n){
        if((s[i]>= 'A' && s[i]<='Z') ||
           (s[i]>= 'a' && s[i]<='z') ||
           (s[i]>= '0' && s[i]<='9')){
            ans=ans+s[i];
           }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
        }
        else{
            while(!st.empty() && priority(s[i] <= priority(st.top()))){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
    
}

int main(){
    string Inf="a+b*c";
    string Pof=Inf2Pof(Inf);
    cout<<Pof;
    return 0;
}
