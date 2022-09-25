#include <cstdio>
#include <climits>

int dp[5001];

int main(){
    int n;
    scanf("%d", &n);

    dp[0]=100000001;
    dp[1]=100000001;
    dp[2]=100000001;
    dp[3]=1;
    dp[4]=100000001;
    dp[5]=1;

    for(int i=6;i<=n;i++){
        dp[i]=(dp[i-3]<dp[i-5])?dp[i-3]+1:dp[i-5]+1;
        //if(dp[i]>1000) dp[i]=1000;

        //printf("%d: %d vs %d => %d\n", i, dp[i-3], dp[i-5], dp[i]);
    }

    printf("%d\n", (dp[n]>=100000001)?-1:dp[n]);

}