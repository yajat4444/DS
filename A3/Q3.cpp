#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main(){
    stack<char> st;
    string input;
    int a=0;
    getline(cin,input);
    for(int i=0;i<input.length();i++){
        if(input[i]=='('||input[i]=='['||input[i]=='{'){
            st.push(input[i]);
        }else if(input[i]==')'||input[i]==']'||input[i]=='}'){
            if(st.empty()){
                
                a=1;
                break;
            }
            else{
                if(input[i]==')'){
                    if(st.top()=='('){
                        st.pop();
                    }else{
                        cout<<"Invalid";
                        a=1;
                        break;
                    }
                }else if(input[i]==']'){
                    if(st.top()=='['){
                        st.pop();
                    }else{
                        cout<<"Invalid";
                        a=1;
                        break;
                    }
                }else if(input[i]=='}'){
                    if(st.top()=='{'){
                        st.pop();
                    }else{
                        cout<<"Invalid";
                        a=1;
                        break;
                    }
                }
            }
        }
    }
    if(a==0&&st.empty()){
        cout<<"Valid";
    }
    else{
        cout<<"Invalid";
    }
}
