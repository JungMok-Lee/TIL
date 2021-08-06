#include <cstdio>
int dp[100001];
int main(){
    int n;
    scanf("%d", &n);

    int a[100001];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);

    dp[0]=a[0];
    int max=a[0];
    for(int i=1;i<n;i++){
        if(dp[i-1]>0) dp[i]=dp[i-1]+a[i]; // dp[i-1]이 양수면 그 뒤에 뭘 더해도 거기서부터 시작하는것보다 낫다.
        else dp[i]=a[i]; // 근데 음수면 거기다 뭘 더하는것보다 앞에거 버리고 거기서부터 시작하는게 낫다.

        // 더 나은 것들을 골라냈으니까 거기 중에서 뭐가 젤 나은지 찾아내야한다.
        if(max<dp[i]) max=dp[i];
    }
    printf("%d", max);

}