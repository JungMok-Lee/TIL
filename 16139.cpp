#include <iostream>
using namespace std;

int count[200001][30]={0,};
int main(){
    string s;
    cin>>s;

    for(int i=0;i<s.length();i++){
        for(int j=0;j<26;j++){
            char n='a'+j;
            if(s[i]==n) count[i][j]+=1;
        }
    }

    int q;
    cin>>q;

    while(q--){
        int l, r;
        char a;
        cin>>a>>l>>r;

    }
}