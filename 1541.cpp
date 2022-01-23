#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    string n;
    bool isMinus=false;
    int ans=0;
    for(int i=0;i<=s.size();i++){
        if(s[i]=='+' || s[i]=='-' || i==s.size()){
            if(isMinus) ans-=stoi(n);
            else ans+=stoi(n);

            // n 초기화
            n="";
        }
        else{
            n+=s[i];
        }

        if(s[i]=='-') isMinus=true;
    }
    cout<<ans<<endl;
}