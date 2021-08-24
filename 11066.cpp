#include <cstdio>
#include <climits>
#include <algorithm>
int dp[510][510];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int k;
        int c[510];
        int sum[510];

        scanf("%d", &k);

        sum[0]=0;
        for(int i=1;i<=k;i++) {
            scanf("%d", &c[i]);
            sum[i]=sum[i-1]+c[i];
            // dp[i][i] 갱신
        }

        for(int dif=1;dif<k;dif++){
            for(int tx=1;tx+dif<=k;tx++){
                int ty=tx+dif;
                dp[tx][ty]=INT_MAX;
                for(int mid=tx;mid<ty;mid++) dp[tx][ty]=std::min(dp[tx][ty], dp[tx][mid]+dp[mid+1][ty]+sum[ty]-sum[tx-1]);
            }
        }
        printf("%d\n",dp[1][k]);

    }
}