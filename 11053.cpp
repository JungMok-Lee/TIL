#include <cstdio>
int a[1010];
int dp[1010]; // dp[i] : i번쨰를 무조건 포함하는 LIS!!!

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0;i<n;i++) scanf("%d", &a[i]);

    dp[0]=1;
    for(int i=1;i<n;i++){
        int max=0;
        for(int j=0;j<i;j++) if(a[j]<a[i] && max<dp[j]) max=dp[j];
        dp[i]=max+1;
    }

    int ans=0;
    for(int i=0;i<n;i++)
        if(ans<dp[i]) ans=dp[i];
    
    printf("%d\n", ans);
}