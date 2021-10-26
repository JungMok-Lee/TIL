#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char s){
    if(s=='*' || s=='/') return 2;
    if(s=='+' || s=='-') return 1;
    if(s=='(' || s==')') return 0;
    else return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin>>input;
    stack<char> s;
    
    for(int i=0;i<input.length();i++){
        if(input[i]>='A' && input[i]<='Z') cout<<input[i];
        else if(input[i]=='(') s.push('(');
        else if(input[i]==')'){
            while(s.top()!='('){
                cout<<s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty() && priority(s.top())>=priority(input[i])){
                cout<<s.top();
                s.pop();
            }
            s.push(input[i]);
        }
    }
    while(!s.empty()) {
        cout<<s.top(); 
        s.pop();
    }
    cout<<"\n";
}