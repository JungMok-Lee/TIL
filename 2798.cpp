#include <cstdio>

int main(){
    int n, m;
    int c[101];
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++) scanf("%d", &c[i]);

    int max=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int sum=c[i]+c[j]+c[k];
                if(sum<=m && max<sum) max=sum;
            }
        }
    }

    printf("%d\n", max);

}