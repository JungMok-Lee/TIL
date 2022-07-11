#include <cstdio>

int dp[12]; // dp[i] : i를 1,2,3으로 나누는 경우의 수
int main(){
    int t;
    scanf("%d", &t);

    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(int i=4;i<12;i++){
        for(int j=1;j<=3;j++){
            dp[i]+=dp[i-j];
        }
    }

    while(t--){
        int n;
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
}