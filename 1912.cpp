#include <cstdio>
int main(){
    int n;
    int a[1000010];
    int dp[1000010];

    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }

    dp[1]=a[1];
    int max=dp[1];
    for(int i=2;i<=n;i++){
        // dp[i-1]이 양수면 뭘 더해도 훨씬 낫다. 
        // 1. 음수에다가 양수 더하기 -> 그냥 자기자신 선택하는게 더 나음.
        // 2. 음수에다가 음수 더하기 -> 차라리 자기자신만 선택하는게 더 낫다.
        if(dp[i-1]>0) dp[i]=dp[i-1]+a[i]; 
        else dp[i]=a[i];

        if(max<dp[i]) max=dp[i];
    }
    printf("%d\n", max);
}