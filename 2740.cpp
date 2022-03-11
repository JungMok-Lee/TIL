#include <cstdio>
int a[100][100];
int b[100][100];


int main(){
    int n, m, k;
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d%d",&m, &k);
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            scanf("%d", &b[i][j]);
        }
    }

    int c[100][100];

    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            for(int k=0;k<m;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

}