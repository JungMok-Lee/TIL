#include <iostream>
using namespace std;

int n, m;
int adj[1010][1010];
int a[1010];

int find(int x){
    if(a[x]==x) return x;
    return a[x]=find(a[x]);
}

void unionn(int x, int y){
    // 서로를 바라보지 않도록 항상 큰쪽으로만 합쳐줘야함!!!
    int u=find(x);
    int v=find(y);
    if(u>v) a[u]=v;
    else a[v]=u;
}

int main(){
    cin>>n>>m;

    for(int i=1;i<=201;i++) a[i]=i;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int tmp;
            scanf("%d", &tmp);
            if(tmp==1) unionn(i, j);
        }
    }


    int s,e;
    cin>>s;
    for(int i=1;i<m;i++){
        cin>>e;
        if(find(s)!=find(e)){
            printf("NO\n");
            return 0;
        }

        s=e;
    }

    printf("YES\n");
    return 0;
}