#include <cstdio>
#include <algorithm>
int dp[101][100010];

int main(){
    int n, k;
    int w[110];
    int v[110];

    scanf("%d%d", &n, &k);
    for(int i=1;i<=n;i++) scanf("%d%d", &w[i], &v[i]);

    // dp[i][j] : i번째 물건까지 고려했을 때 j 무게의 가방이 됐을 떄의 총 가치
    // 그렇다면 가방에 i번째 물건을 넣는 경우와 안 넣는 경우가 있다.
    // 일단 i번째 물건이 들어가면 무조건 가방 무게 j는 i번째 물건보다 커지게 되어 있다. (j>=w[i]). 따라서 들어가면 j>=w[i]이고, 안 들어가면 j<w[i]이다.
    // 그런데 이번 물건을 아예 안 넣는게 더 이득일 경우가 있다. j>=w[i]일때도. 그 세 가지 경우만 고려해주면 문제를 풀 수 있다.
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            // j>=w[i]는 만들고자 하는 가방 무게가 일단 지금 넣으려는 것보다는 작아야 한다는 이야기이다.
            if(j>=w[i]) dp[i][j]=std::max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    printf("%d\n", dp[n][k]);

}