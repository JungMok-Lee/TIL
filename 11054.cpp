#include <cstdio>
/*
    가장 긴 증가하는 부분 수열을 두번 활용하는 문제
    dp_up[i] : i번째 원소를 포함하는 가장 긴 증가하는 부분 수열 (0번째부터 i번째까지만 봤을 때)
    dp_down[i] : i번째 원소를 포함하는 가장 긴 감소하는 부분 수열 (i번째부터 마지막번째까지만 봤을 떄)
    dp_up[i]+dp_down[i]-1이 i번째 원소를 중심으로 한 가장 긴 바이토닉 부분 수열의 길이가 되므로, 
    max(dp_up[i]+dp_down[i]-1)을 찾으면 됨.
*/
int main(){
    int n;
    int a[1001];
    int dp_up[1001];
    int dp_down[1001];

    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &a[i]);
        dp_up[i]=1;
        dp_down[i]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j] && dp_up[i]<dp_up[j]+1) dp_up[i]=dp_up[j]+1;
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(a[i]>a[j] && dp_down[i]<dp_down[j]+1) dp_down[i]=dp_down[j]+1;
        }
    }

    int max=0;
    for(int i=0;i<n;i++) if(dp_up[i]+dp_down[i]-1>max) max=dp_up[i]+dp_down[i]-1;
    printf("%d", max);
}