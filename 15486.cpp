#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int t[15000001];
int p[15000001];
int dp[15000001];

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d%d", &t[i], &p[i]);
        dp[i]=0;
    }
    dp[n]=0;

    for(int i=n-1;i>=0;i--){
        if(i+t[i]>n) dp[i]=dp[i+1];
        else{
            dp[i]=max(dp[i+t[i]]+p[i], dp[i+1]); // 그날 업무 하는 거랑 안하는 것 중에 큰 것 고르기.
        }
    }

    printf("%d\n", dp[0]);
}