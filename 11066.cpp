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
        }

        /*
            dp[i][j] : i번째 에서 j번째까지 파일을 정리할 떄의 최솟값.
            dp[i][i+1]을 모든 i에 대해서 계산해주고, 그다음은 dp[i][i+2], dp[i][i+3] ... 쭉쭉 이런 식으로 계산해 나가면 된다.
            여기서 해당 값을 어떻게 구하는가 : i번째에서 mid까지의 최솟값 + mid+1번째에서 j번째까지의 최솟값 + 앞에 두개를 합치는 비용(앞에 두개를 합치면 결국 c[i]부터 c[j]까지 모두 더한 게 된다)

            이 점화식의 안 좋은 점 : dp[i][i]는 무조건 0으로 초기화 되어있어야 돌아간다. 즉 dif=1일때, sum[ty]-sum[tx-1]이므로 dp[tx][mid], dp[mid+1][ty]가 모두 0이어야 한다.
            그러나 그 이외의 값에서는 모두 돌아간다.

            내가 생각했던 의문점. 만약 dp[1][3]을 구한다고 했을 떄
            1 2를 먼저 합칠 떄 (즉 dp[1][2]+dp[3][3]+sum[3]), 2 3을 먼저 합칠 떄 (즉 dp[1][1]+dp[2][3]+sum[3])은 고려하면서 왜
            1 3을 먼저 합칠 때를 고려하지 않는가였다(이것은 이 점화식으로 표현 불가). 문제를 읽어보면, 1장 2장 순서를 고려하면서 합치는 듯한? 어조를 주기 떄문에 우리도 1,3 을 먼저 합칠 수는 없다
            즉 순서가 섞이지 않게 하면서 합쳐야 한다. 따라서 이런 경우까지 고려하지 않아도 된다.
        */
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