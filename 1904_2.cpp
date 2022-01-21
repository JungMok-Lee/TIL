#include <cstdio>


int main(){
    int n;
    scanf("%d", &n);

    long long dp[1000001];
    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=n;i++) dp[i]=(dp[i-1]+dp[i-2])%15746;
    printf("%lld\n", dp[n]);
}