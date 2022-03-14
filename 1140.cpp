#include <cstdio>
#include <climits>
int n;
int g[101][101];
int d[101][101];



int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &g[i][j]);
            if(!g[i][j]) d[i][j]=100;
            else d[i][j]=g[i][j];
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][k]+d[k][j]<d[i][j]) d[i][j]=d[i][k]+d[k][j];
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", (d[i][j]!=100)?1:0);
        }
        printf("\n");
    }



}