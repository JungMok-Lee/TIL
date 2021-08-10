#include <cstdio>
#include <algorithm>

/*
    어제 문제에서 무조건 마지막 잔을 마신다에 대한 dp 문제를 풀어서 마지막 잔을 무조건 마시는 
    경우밖에 고려를 못했다. 맴아픔
    근데 무조건 마지막 잔을 마신다고 생각해서 dp 점화식을 바로 세웠다.
    계단 문제랑 비슷한데, 맨 마지막 계단을 무조건 밟는다고 생각했을 떄
    바로 전 계단을 밟느냐 안밟느냐로 경우를 나눌 수 있었다.
*/
int main(){
    int n;
    scanf("%d", &n);

    int k[100001];
    int dp[100001];
    dp[0]=0;

    for(int i=1;i<=n;i++){
        scanf("%d", &k[i]);
        if(i==1) dp[i]=k[i];
        else if(i==2) dp[i]=k[1]+k[2];
        else {
            dp[i]=std::max(dp[i-2]+k[i], dp[i-3]+k[i-1]+k[i]);
            dp[i]=std::max(dp[i-1], dp[i]);
        }
    }
    printf("%d\n", dp[n]);
}