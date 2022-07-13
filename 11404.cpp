#include <cstdio>

#define INF 987654321
int adj[101][101]={INF, };

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adj[i][j]=INF;
        }
    }

    for(int i=0;i<m;i++){
        int s, e, w;
        scanf("%d%d%d", &s, &e, &w);
        if(adj[s][e]>w) adj[s][e]=w;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(adj[j][k]>adj[j][i]+adj[i][k] && adj[j][i]!=INF && adj[i][k]!=INF) 
                    adj[j][k]=adj[j][i]+adj[i][k];
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(adj[i][j]>=INF || i==j) printf("0 ");
            else printf("%d ", adj[i][j]);
        }
        printf("\n");
    }



}