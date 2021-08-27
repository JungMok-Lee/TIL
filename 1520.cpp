#include <iostream>
#include <algorithm>
#include <memory.h>

/*
문제 자체는 dfs와 dp 메모이제이션을 결합한 문제.
dfs가 기억이 안난다 싶었지만 수업 때 했던 미로 문제와 굉장히 비슷함. 거의 동일.
그러나 dfs, 미로 개념이 없어서 잘 틀렸음.

아이디어는 dp[i][j] : input[i][j]까지 가는 경우의 수
이것을 dfs로 어떻게 푸는가?
*/
using namespace std;
int n, m;
int input[501][501];
int dp[501][501];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
 
int dfs(int row, int col){
    if(dp[row][col]!=-1) return dp[row][col]; // 이미 초기화가 되어 있다면 그 값을 그대로 리턴 (메모이제이션)
    if(row<0 || row>=m || col<0 || col>=n) return 0; // 미로 밖 값을 탐지하면 그냥 0을 주기 (그래서 dfs(nx, ny)더할 때 안 더해짐)
    if(row==0 && col==0) return 1; // 기저 사례

    dp[row][col]=0;
    for(int i=0;i<4;i++){
        int nx=row+dx[i]; // 이전 박스의 x좌표 
        int ny=col+dy[i]; // 이전 박스의 y좌표
        if(input[nx][ny]>input[row][col]) dp[row][col]+=dfs(nx, ny); // 아래로 내려오는 형태일때(현재가 이전보다 작을 때) 그 방향 움직임이 가능, 그래서 경우의 수에 더해주기.
    }
    return dp[row][col];
}
 
int main(){
    cin>>m>>n;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &input[i][j]);

    memset(dp, -1, sizeof(dp));
    printf("%d\n", dfs(m-1, n-1));
    return 0;

}