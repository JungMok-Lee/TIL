// bfs로 푸는 문제 왜 ??????
#include <cstdio>
#include <queue>
using namespace std;

int n, m;

// for graph traversal
int a[101][101];
int v[101][101];

// for counting the #
int c[101][101];

// for next x and next y
int dx[4]={0, 0, -1, 1};
int dy[4]={1, -1, 0, 0};


void bfs(){
    v[0][0]=1;

    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !v[nx][ny] && a[nx][ny]){
                v[nx][ny]=1;
                q.push(make_pair(nx, ny));
                c[nx][ny]=c[x][y]+1;
            }
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &a[i][j]);
        }
    }

    bfs();

    printf("%d\n", c[n-1][m-1]+1);


}