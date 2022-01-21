#include <iostream>
using namespace std;

int dp[40][2];

int main(){
    int t;
    cin>>t;

    dp[0][0]=1;
    dp[0][1]=0;
    dp[1][0]=0;
    dp[1][1]=1;

    for(int i=2;i<=40;i++){
        dp[i][0]=dp[i-1][0]+dp[i-2][0];
        dp[i][1]=dp[i-1][1]+dp[i-2][1];
    }
    
    while(t--){
        int n;
        cin>>n;
        cout<<dp[n][0]<<' '<<dp[n][1]<<'\n';
    }   
}