#include <cstdio>
#include <queue>

using namespace std;

int n, m;
int adj[1010][1010];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<pair<int, int> > q;

void bfs(){
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(adj[ny][nx]==0 && nx>=0 && nx<m && ny>=0 && ny<n){
                adj[ny][nx] = adj[y][x]+1;
                q.push(make_pair(ny, nx));
            }
        }

        q.pop();

    }
}

int main(){
    scanf("%d%d", &m, &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &adj[i][j]);
            if(adj[i][j]==1) q.push(make_pair(i, j));
        }
    }

    bfs();

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]==0){
                printf("-1\n");
                return 0;
            }
            if(ans<adj[i][j]) ans = adj[i][j];
        }
    }
    printf("%d\n", ans-1);
    return 0;

}