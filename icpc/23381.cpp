#include <cstdio>
int p[3001];
int dp[3010][3010];

int main(){
    int n;
    scanf("%d", &n);

    for(int i=1;i<=n;i++){
        scanf("%d", &p[i]);
    }

    for(int i=1;i<=n;i++) dp[1][i]=p[1];

    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i-j][j] + p[i];
        }
    }

    int mx = 0;
    for(int i=1;i<=3000;i++){
        if(dp[i][1]>mx) mx=dp[i][1];
    }
    printf("%d\n", mx);
}