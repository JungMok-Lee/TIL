#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

int n, m;
int adj[101][101]={0,};
int path[101]={10000000, };
bool v[101];

int bfs(int s){
    queue<int> q;
    q.push(s);

    memset(path, 0, sizeof(path));
    memset(v, false, sizeof(v));

    while(!q.empty()){
        int x=q.front();
        v[x]=true;
        q.pop();
        for(int i=1;i<=101;i++){
            if(adj[x][i]==1 && !v[i]){
                q.push(i);
                v[i]=true;
                path[i]=path[x]+1;
            }
        }
    }

    int sum=0;
    for(int i=1;i<=n;i++) sum+=path[i];
    return sum;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a][b]=1;
        adj[b][a]=1;
    }
    
    int max=10000;
    int argmax=0;
    for(int i=1;i<=n;i++){
        int c=bfs(i);
        if(max>c) {
            max=c;
            argmax=i;
        }
    }
    printf("%d\n", argmax);
}