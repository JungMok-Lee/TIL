#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int n, m;
vector<int> adj[100001];
bool v[100001]={false,};
int ans[100001]={0,};

void dfs(int k){
    for(int i=0;i<adj[k].size();i++){
        int x=adj[k][i];
        ans[x]+=ans[k];
        dfs(x);
    }    
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d", &k); // 직속 상사
        if(k!=-1) adj[k].push_back(i); // 상사->후배
    }
    for(int i=1;i<=m;i++){
        int k, w;
        scanf("%d%d", &k, &w);
        ans[k]+=w;
    }
    dfs(1);

    for(int i=1;i<=n;i++) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}