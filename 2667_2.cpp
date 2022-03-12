#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[25][25];
bool v[25][25];
int c[25][25]={1,};

int dx[4]={0, 0, -1, 1};
int dy[4]={1, -1, 0, 0};

int bfs(int sx, int sy){
    v[sx][sy]=true;

    int max=0;
    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        max++; // 이게 집 수를 세는 역할을 함
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<n &&ny>=0 && ny<n && !v[nx][ny] && a[nx][ny]){
                v[nx][ny]=true;
                q.push(make_pair(nx, ny));
                c[nx][ny]=c[x][y]+1;
            }
        }
    }

    return max;
}

vector<int> h;
void insert(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!v[i][j] && a[i][j]){
                h.push_back(bfs(i, j));
            }
        }
    }
    sort(h.begin(), h.end());
}

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d", &a[i][j]);
        }
    }
    
    insert();

    printf("%d\n", h.size());
    for(int i=0;i<h.size();i++) printf("%d\n", h[i]); 

}