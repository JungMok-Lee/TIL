#include <cstdio>
#include <vector>
using namespace std;

int n, m;
int adj[101][101];

int main(){
    int a, b;
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;i++){
        scanf("%d%d", &a, &b);
        adj[a][b]=1;
        adj[b][a]=1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && adj[i][j] != 1) {
                adj[i][j] = 10000000;
            }
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(adj[i][k]+adj[k][j]<adj[i][j]){
                    adj[i][j]=adj[i][k]+adj[k][j];
                }
            }
        }
    }

    int max=10000000;
    int person=0;
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=n;j++){
            sum+=adj[i][j];
        }
        if(sum<max) {
            max=sum;
            person=i;
        }
    }

    printf("%d\n", person);

    

}