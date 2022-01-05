#include <cstdio>
#include <vector>
using namespace std;

int n,m;
vector<int> adj[1000000];
bool visit[1000000];

void dfs(int x){
    if(visit[x]) return;

    visit[x]=true;
    for(int i=0;i<adj[x].size();i++){
        if(!visit[adj[x][i]]) dfs(adj[x][i]);
    }
}

int main(){
    int u, v;
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;i++){
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            dfs(i);
            cnt++;
        }
    }
    printf("%d\n", cnt);
}