#include <cstdio>
#include <vector>
using namespace std;

int n; 
bool v[1001];
int adj[1001]; // adj[a]=b : a의 자식이 b다

void dfs(int x){
    if(v[x]) return;
    v[x]=true;
    if(adj[x]) dfs(adj[x]);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=1;i<=n;i++) scanf("%d", &adj[i]);

        int cnt=0;
        for(int i=1;i<=n;i++){
            if(!v[i]) {
                dfs(i);
                cnt++;
            }
        }
        for(int i=1;i<=n;i++) {
            v[i]=false;
            adj[i]=0;
        }

        printf("%d\n", cnt);
    }
}