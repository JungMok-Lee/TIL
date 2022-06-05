#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int t[100]={0,}; 
    int p[100]={0,};
    int dp[100]={0,};

    for(int i=1;i<=n;i++){
        scanf("%d%d", &t[i], &p[i]);
        for(int j=0;j<i;j++){
            if(t[j]+j<=i && i+t[i]<=n+1){
                dp[i]=max(dp[i], dp[j]+p[i]);
            }
        } 
    }

    int ans=0;
    for(int i=1;i<=n;i++) if(dp[i]>ans) ans=dp[i];
    printf("%d\n", ans);
}