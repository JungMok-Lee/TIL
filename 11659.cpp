#include <cstdio>

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int a[100001];
    int s[100001];
    s[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        s[i]=s[i-1]+a[i];
    }
    
    for(int iter=0;iter<m;iter++){
        int i, j;
        scanf("%d%d", &i, &j);
        printf("%d\n", s[j]-s[i-1]);
    }

}