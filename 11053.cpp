#include <cstdio>
#include <algorithm>

/*  
    약간 풀어지는 중..
    생각해보기보다 그냥 인터넷 보고 단적인 이해만 하고 있다.
    이 문제는 엄청 중요한 문제 같은데
    또 보고 다시 커밋해서 여기 주석 부분을 설명으로 고쳐야겠다!!! 오늘이 넘어서라도!!
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
            if(a[j]<a[i] && dp[j]+1>dp[i]) dp[i]=dp[j]+1;
            else if(a[j]==a[i] && dp[j]>dp[i]) dp[i]=dp[j];
        }
    }
    int max=0;
    for(int i=0;i<n;i++) if(dp[i]>max) max=dp[i];
    printf("%d\n",max);
}