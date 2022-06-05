#include <cstdio>

int adj[401][401];

int main(){
    int v,e;
    scanf("%d%d", &v, &e);
    
    for(int i=0;i<e;i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a][b]=c;
    }
}