#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n;
char a[20][20];
vector<string> v;
set<string> s;

void count(int x, int y, string p){
    int l=p.size();
    if(l==2*n-1) s.insert(p);
    
    else if(l<n){
        if(x<n-1) count(x+1, y, p+a[x+1][y]);
        if(y<n-1) count(x, y+1, p+a[x][y+1]); 
        if(x<n-1 && y<n-1) count(x+1, y+1, p+a[x+1][y+1]);
    }

    else{
        if(x<n-1 && a[x+1][y]==int(p[2*n-2-l])) count(x+1, y, p+a[x+1][y]);
        if(y<n-1 && a[x][y+1]==int(p[2*n-2-l])) count(x, y+1, p+a[x][y+1]);
        if(x<n-1 && y<n-1 && a[x+1][y+1]==int(p[2*n-2-l])) count(x+1, y+1, p+a[x+1][y+1]);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    string input;
    input += a[0][0];
    count(0, 0, input);

    cout<<s.size()<<"\n";
    
}