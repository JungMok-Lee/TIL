#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

int n,m,v;
int visit[1001]={0,};
int adj[1001][1001];

void dfs(int k){
    //if(visit[k]==1) return;

    visit[k]=1;
    printf("%d ", k);
    for(int i=1;i<=n;i++){
        if(adj[k][i]==1 && !visit[i]) dfs(i);
    }
}

void bfs(){
    queue<int> q;
    q.push(v);
    visit[v]=1;

    while(!q.empty()){
        int k=q.front();
        printf("%d ", k);
        q.pop();

        for(int i=1;i<=n;i++){
            if(adj[k][i]==1 && visit[i]==0){
                q.push(i);
                visit[i]=1;
            }
        }
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &v);
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a][b]=1;
    }

    dfs(v); printf("\n");
    memset(visit, 0, sizeof(visit));
    bfs(); printf("\n");
}