#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1000001];

int main(){
    int n;
    scanf("%d", &n);

    dp[0]=1000000;
    
    memset(dp, 10000, sizeof(dp));
    dp[1]=0;

    for(int i=2;i<=n;i++){
        if(i%6==0){
            dp[i]=min(dp[i], dp[i/3]+1);
            dp[i]=min(dp[i], dp[i/2]+1);
            dp[i]=min(dp[i], dp[i-1]+1);
        }
        else if(i%3==0){
            dp[i]=min(dp[i], dp[i/3]+1);
            dp[i]=min(dp[i], dp[i-1]+1);
        }
        else if(i%2==0){
            dp[i]=min(dp[i], dp[i/2]+1);
            dp[i]=min(dp[i], dp[i-1]+1);
        }
        else{
            dp[i]=min(dp[i], dp[i-1]+1);
        }
    }
    printf("%d\n", dp[n]);
}