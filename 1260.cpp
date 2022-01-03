#include <cstdio>
#include <queue>
using namespace std;

int n, m, v;
int visit[1001];
int adj[1001][1001];

void dfs(int x){
    visit[x]=true;
    printf("%d ", x);
    for(int i=1;i<=n;i++){
        if(adj[x][i]==1 && !visit[i]) dfs(i);
    }
}

void bfs(int s){
    queue<int> q;
    q.push(s);
    visit[s]=false;

    while(!q.empty()){
        int x=q.front();
        printf("%d ", x);
        q.pop();

        for(int i=1;i<=n;i++){
            if(adj[x][i]==1 && visit[i]){ // visit를 반대로 활용 (true: 접속 안함)
                q.push(i);
                visit[i]=false;
            }
        }
    }
}

int main(){
    int a, b;
    scanf("%d%d%d", &n, &m, &v);
    for(int i=0;i<m;i++){
        scanf("%d%d", &a, &b);
        adj[a][b]=1; adj[b][a]=1;
    }

    dfs(v);
    printf("\n");
    bfs(v);
    printf("\n");
}