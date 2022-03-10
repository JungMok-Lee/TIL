#include <cstdio>

int n;
bool visit[25][25];
int adj[25][25];

int dx[4]={0, 0, -1, 1};
int dy[4]={1, -1, 0, 0};

void dfs(int sx, int sy, int x, int y){
    if(visit[x][y]) return;

    visit[x][y]=true;

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=0 && ny<n && ny>=0 && ny<n && adj[nx][ny]==1 && !visit[nx][ny]){
            dfs(sx, sy, nx, ny);
        }
    }

}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        char a[25];
        scanf("%s", a);
        for(int j=0;j<n;j++) adj[i][j]=a[j];
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visit[i][j] && adj[i][j]==1){
                dfs(i, j, i, j);
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);

}