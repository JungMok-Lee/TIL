#include <stdio.h>

int main(){
    int n,k;
    scanf("%d%d", &n, &k);

    int a[11];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);

    int count=0;
    for(int i=n-1;i>=0;i--){
        while(k-a[i]>=0){
            k-=a[i];
            count++;
        }
    }
    printf("%d\n", count);
}