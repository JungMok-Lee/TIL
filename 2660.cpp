#include <cstdio>
int adj[51][51]={1000000,};

int main(){
    int n;
    scanf("%d", &n);
    
    int a=0, b=0;
    while(a!=-1 && b!=-1){
        scanf("%d%d", &a, &b);
        adj[a][b]=1;
        adj[b][a]=1;
    }

    for(int s=1;s<=n;s++){
        for(int e=1;e<=n;e++){
            for(int m=1;m<=n;m++){
                if(adj[s][e]>adj[s][m]+adj[m][e]){
                    adj[s][e]=adj[s][m]+adj[m][e];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}