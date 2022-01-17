#include <cstdio>

int main(){
    int n;
    int x[51]; int y[51];
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d%d", &x[i], &y[i]);


    int k[51]={0,};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(x[i]<x[j] && y[i]<y[j]) k[i]++;
        }
    }
    for(int i=0;i<n;i++) printf("%d ", k[i]+1);
    printf("\n");

    return 0;
}