#include <cstdio>

#define MOD 1000000000

int main(){
    int n;
    scanf("%d", &n);
    
    int dp[101][11]={0,};
    for(int i=0;i<=9;i++) dp[1][i]=1;

    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i-1][1];
        dp[i][10]=0;
        for(int j=0;j<=9;j++) dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%MOD;
    }

    int sum=0;
    for(int i=1;i<=9;i++) sum=(sum+dp[n][i])%MOD;
    printf("%d\n", sum);
}