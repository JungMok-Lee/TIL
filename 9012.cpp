#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        stack<int> st;

        bool flag=true;

        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push(1);
            else{
                if(st.empty()){
                    cout<<"NO"<<endl;
                    flag=false;
                    break;
                }
                else st.pop();
            }
        }

        if(st.empty() && flag) cout<<"YES"<<endl;
        else if(flag) cout<<"NO"<<endl;
    }
}

/*
if(st.empty()){
                    cout<<"NO"<<endl;
                    i=s.length();
                }
*/