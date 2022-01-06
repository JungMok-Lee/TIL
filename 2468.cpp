#include <cstdio>
#include <string.h>
using namespace std;

int n;
int adj[101][101];
int v[101][101];

int dx[4]={0, 0, -1, 1};
int dy[4]={1, -1, 0, 0};

void dfs(int sub, int y, int x){
    if(adj[y][x]-sub<0) return; // 잠시면 세지 마!
    v[y][x]=1;
    //printf("%d %d passed\n", y, x);

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<n && !v[ny][nx] && adj[y][x]-sub>=0) dfs(sub, ny, nx);
    }   
}

int cnt(int sub){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //printf("~%d %d\n", adj[j][i], sub);
            if(!v[j][i] && adj[j][i]-sub>=0){
                //printf("%d %d\n", j, i);
                cnt++;
                dfs(sub, j, i);
            }
        }
    }
    return cnt;
}
int main(){
    scanf("%d", &n);
    int min=101, max=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &adj[i][j]);
            if(adj[i][j]<min) min = adj[i][j];
            if(adj[i][j]>max) max = adj[i][j];
        }
    }

    //printf("%d %d\n", min, max);

    int max_k=0;
    for(int i=min;i<=max;i++){
        int k = cnt(i);
        //printf("k = %d\n", k);
        if(max_k<k) max_k=k;
        memset(v, 0, sizeof(v));
    }
    printf("%d\n", max_k);
    return 0;


}