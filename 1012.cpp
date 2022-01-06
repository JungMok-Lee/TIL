#include <cstdio>
#include <string.h>
using namespace std;

int n,m,k;
int adj[51][51];
bool v[51][51];

int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};

void dfs(int y, int x){
    v[y][x]=true;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx>=0 && nx<m && ny>=0 && ny<n && adj[ny][nx]==1 && !v[ny][nx]){
            dfs(ny, nx);
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        memset(adj,0,sizeof(adj));
        memset(v,0,sizeof(v));

        scanf("%d%d%d", &m, &n, &k);
        int x, y;
        for(int i=0;i<k;i++){
            scanf("%d%d", &x, &y);
            adj[y][x]=1;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!v[i][j] && adj[i][j]){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
}