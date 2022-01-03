#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int a[310][310];
int d[310][310];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, sx, sy, ex, ey;
        scanf("%d", &n);
        queue<pair<int, int> > q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) d[i][j]=-1;
        }
        scanf("%d%d", &sx, &sy);
        scanf("%d%d", &ex, &ey);
        q.push(make_pair(sx, sy));

        a[sx][sy]=1;
        d[sx][sy]=0;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;

            for(int i=0;i<8;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<n && a[nx][ny]==0 && d[nx][ny]==-1){
                    q.push(make_pair(nx, ny));
                    d[nx][ny]=d[x][y]+1;
                    a[nx][ny]=1;
                }
            }
            q.pop();
        }

        printf("%d\n", d[ex][ey]);

        memset(a, 0, sizeof(a));
        memset(d, -1, sizeof(d));
    }
}