#include <cstdio>

int a[1000010];

int find_(int x){
    if(a[x]==x) return x;
    return a[x] = find_(a[x]); // 메모이제이션
}

void union_(int x, int y){
    int px = find_(x);
    int py = find_(y);
    
    if(px>py) a[px]=py;
    else a[py]=px;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++) a[i]=i;

    while(m--){
        int aa, b, c;
        scanf("%d%d%d", &aa, &b, &c);

        // 합집합
        if(!aa) union_(b, c);
        else{
            if(find_(b)==find_(c)) printf("YES\n");
            else printf("NO\n");
        }
    }
}