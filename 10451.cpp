#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

int n;
vector<int> adj[1001];
bool v[1001];

int dfs(int x){
    if(v[x]) return 0;
    int ret=x;
    v[x]=true;
    for(int i=0;i<adj[x].size();i++){
        if(!v[adj[x][i]]) {
            ret = dfs(adj[x][i]);
            if(ret==x) {
                //printf("got here!\n");
                return x;
            }
        }
    }
    for(int i=0;i<adj[ret].size();i++){
        if(adj[ret][i]==x) return x;
    }
    return ret;
}

int main(){
    int t, k;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            scanf("%d", &k);
            adj[i].push_back(k);
        }
        
        int cnt=0;
        for(int i=1;i<=n;i++){
            k=dfs(i);
            if(i==k) {
                cnt++;
            }
            //printf("!!!%d %d!!!\n", i, k);
        }
        printf("%d\n", cnt);
        memset(adj, 0, sizeof(adj));
        memset(v, false, sizeof(v));

        // 미해결 부분: 하나의 노드가 두개의 사이클을 가지고 있을 수도 있다. 현재는 모두 하나로 카운트.
        // 난 모르겠지만 맞았습니다! 라고 떴다 완전 신기 나 좀 대박인거같음지금
    }
}