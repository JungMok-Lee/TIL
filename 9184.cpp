#include <cstdio>
int dp[51][51][51];

// 재귀에 단순히 배열의 메모이제이션만 추가해주면 된다. 
int w(int a, int b, int c){
    if(a<=0 || b<=0 || c<=0) return dp[0][0][0]=1;
    else if(a>20 || b>20 || c>20) return dp[20][20][20]=1048576;
    else if(dp[a][b][c]) return dp[a][b][c];
    else if(a<b && b<c) return dp[a][b][c]=w(a, b, c-1)+w(a, b-1, c-1)-w(a, b-1, c);
    else return dp[a][b][c]=w(a-1, b, c)+w(a-1, b-1, c)+w(a-1, b, c-1)-w(a-1, b-1, c-1);
}
int main(){
    int a,b,c;
    while(true){
        scanf("%d%d%d", &a, &b, &c);
        if(a==b & b==c & a==-1) break;
        else printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    } 
}