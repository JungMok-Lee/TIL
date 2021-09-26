#include <cstdio>
int n, s;
int a[20];
int cnt=0;

void dfs(int sum, int idx){
    if(sum==s and idx!=0) cnt++;
    if(idx==n) return;
    
    for(int i=idx;i<n;i++){
        dfs(sum+a[i], i+1);
    }
}

int main(){
    scanf("%d%d", &n, &s);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    dfs(0, 0);
    printf("%d\n", cnt);
}