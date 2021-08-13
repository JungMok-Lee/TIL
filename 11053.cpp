#include <cstdio>
#include <algorithm>

/*  
    이 문제 풀이가 굉장히 많지만 일단 dp로.
    dp[i] : i번째 원소를 포함하는 가장 긴 증가하는 부분수열의 길이
    이렇게 하면 dp[i]가 
    a[i] 이전의 원소들 중에서 a[i]보다 작은 i의 dp[i]+1 한 것이다. (이전 원소들 중 현재 원소보다 작은 것들 중에 가장 긴 부분수열 길이에, 현재 원소를 붙여준다.)
    이렇게 되면 dp 중 max를 찾으면 문제가 바로 풀린다.
*/
int main(){
    int n, ans;
    int a[1001];
    int dp[1001];

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        dp[i]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j] && dp[i]<dp[j]+1) dp[i]=dp[j]+1;
            // if(a[i]>a[j]) dp[i]=max(dp[i], dp[j+1]) 과 동일
        }
    }
    int max=0;
    for(int i=0;i<n;i++) if(dp[i]>max) max=dp[i];
    printf("%d\n",max);
}