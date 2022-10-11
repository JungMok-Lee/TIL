#include <cstdio>

int a[100001];

int find_(int x){
    if(a[x]==x) return x;
    return a[x] = find_(a[x]);
}

void union_(int x, int y){
    a[find_(x)]=find_(y);
}

int main(){
    int g, p;
    scanf("%d%d", &g, &p);

    for(int i=1;i<=g;i++) a[i]=i;

    int ans=0;
    while(p--){
        int tmp;
        scanf("%d", &tmp);

        if(find_(tmp)==0) break;

        ans++;
        union_(find_(tmp), find_(tmp)-1);
    }

    printf("%d", ans);
}