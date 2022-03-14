#include <cstdio>

int main(){
    int n;
    int a[1001];
    int dp[1001];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
        dp[i]=1;
    }

    dp[0]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]>a[i] && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
            }
        }
    }

    int max=0;
    for(int i=0;i<n;i++){
        if(max<dp[i]) max=dp[i];
    }

    printf("%d\n", max);
}