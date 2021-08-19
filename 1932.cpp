#include <cstdio>
#include <algorithm>
int tri[501][501];
int dp[501][501];

/*
    tri[i][j] : i번째줄 j번째에 오는 숫자
    dp[i][j] : i번째줄 j번째를 포함했을 때 합이 최대가 되는 합
    j가 1 또는 마지막 숫자면 바로 위에서 내려올 수 밖에 없다 (양 끝 수라 각각 왼쪽 오른쪽이 존재 x)
    그 이외 경우는 바로 위에 왼쪽 숫자(dp[i-1][j-1])와 바로 위에 있는 숫자(dp[i-1][j]) 중 큰 거에 i번째줄 j 번째오는 숫자를 더한 것
    최대값은 마지막 줄(n번째 줄) 에서 dp의 최대값
*/
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d", &tri[i][j]);
        }
    }
    dp[1][1]=tri[1][1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==1) dp[i][j]=dp[i-1][j]+tri[i][j];
            else if(j==i) dp[i][j]=dp[i-1][j-1]+tri[i][j];
            else{
                dp[i][j]=std::max(dp[i-1][j-1], dp[i-1][j])+tri[i][j];
            }
        }
    }
    int max=-1; 
    for(int i=1;i<=n;i++) if(max<dp[n][i]) max=dp[n][i];
    printf("%d\n", max);

}