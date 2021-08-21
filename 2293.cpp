#include <cstdio>
int dp[100010];
int c[110];

/* dp[i] : i원을 만드는 경우의 수. 
   0원을 만드는 경우의 개수는 아무것도 사용하지 않는 1개.
*/
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=1;i<=n;i++) scanf("%d", &c[i]);


    dp[0]=1;
    for(int i=1;i<=n;i++){
        // 내가 c[i]원을 이미 사용했을 때. j원을 만드는 경우의 수는 dp[j-c[i]]
        // 이걸 모든 c[i]에 대해서 진행하고 dp는 그 경우를 모두 합친 것이므로 더해주면 된다.
        for(int j=c[i];j<=k;j++) dp[j]+=dp[j-c[i]];
    }
    printf("%d\n", dp[k]);
}