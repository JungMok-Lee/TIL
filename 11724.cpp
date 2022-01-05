#include <cstdio>
#include <vector>
#include <queue>
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

void bfs(int s){ // starting point 
    if(visit[s]) return;

    queue<int> q;
    q.push(s);
    visit[s]=true;

    while(!q.empty()){
        int x=q.front();
        q.pop();

        for(int i=0;i<adj[x].size();i++){
            if(!visit[adj[x][i]]){
                q.push(adj[x][i]);
                visit[adj[x][i]]=true;
            }
        }
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
            bfs(i);
            cnt++;
        }
    }
    printf("%d\n", cnt);
}