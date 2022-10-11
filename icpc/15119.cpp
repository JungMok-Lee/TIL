#include <iostream>
#include <string>
using namespace std;

string s;
int sum[100010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    
    sum[0]=0;

    for(int i=1;i<=s.length();i++){
        if(s[i-1]=='B') sum[i]=sum[i-1]+1;
        else sum[i]=sum[i-1]-1;
    }

    int max=0;
    int min=0;
    for(int i=0;i<=s.length();i++){
        if(sum[min]>sum[i]) min=i;
        if(sum[max]<sum[i]) max=i;
    }

    if(max<min){
        int temp=min;
        min=max;
        max=temp;
    }
    
    cout<<min+1<<" "<<max<<endl;
}