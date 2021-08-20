#include <cstdio>
int dp[2001][2001];
int pal[2001];

int main(){
    int n, m;
    scanf("%d", &n);

    for(int i=0;i<n;i++) scanf("%d", &pal[i]);
    
    // 길이 1짜리 팰린드롬
    for(int i=0;i<n;i++) dp[i][i]=1;

    // 길이 2짜리 팰린드롬
    for(int i=0;i<n-1;i++) {
        if(pal[i]==pal[i+1]) dp[i][i+1]=1;
    }

    /* 길이 3 이상 팰린드롬. 
       i는 스타트를 말하는 게 아니라 팰린드롬의 길이를 의미한다.
       바로 전 까지의 팰린드롬 (dp[j-1][j+i-1]) 이 팰린드롬이고 현재 양 끝이 같으면 팰린드롬
       길이 별로 나누고 i가 스타트를 말하지 않는 이유가
       start를 i, end를 j로 두게 되면 dp[i+1][j-1]이 팰린드롬인지 체크가 불가능해짐(i번째 이전까지만 dp가 값이 제대로 부여된 상태)
       따라서 길이별로 이렇게 경우의 수를 나누고 i를 팰린드롬의 길이로 두고 문제를 풀어야 한다.
    */
    for(int i=2;i<n;i++){
        for(int j=0;j<n-i;j++) if(pal[j]==pal[j+i] && dp[j+1][j+i-1]) dp[j][j+i]=1;
    }

    scanf("%d", &m);

    for(int i=0;i<m;i++){
        int s, e;
        scanf("%d%d", &s, &e);
        printf("%d\n", dp[s-1][e-1]);
    }

}