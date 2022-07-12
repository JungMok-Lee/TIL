#include <cstdio>
#include <cmath>
int c, g; // c: chu, g: goosle
int cw[31];
int gw[8];

bool dp[31][45000]={false, };// i번째까지 고려했을 때 j무게를 만들 수 있는가?

void f(int i, int w){
    if(i>c) return;
    if(w>40000) return;
    if(dp[i][w]) return; // 이거 안 넣어주면 시간 초과 난다!!!!!!

    dp[i][w]=true;
    f(i+1, w+cw[i]);
    f(i+1, w);
    f(i+1, abs(w-cw[i]));
}

int main(){
    scanf("%d", &c);
    for(int i=0;i<c;i++) scanf("%d", &cw[i]);
    scanf("%d", &g);
    for(int i=0;i<g;i++) scanf("%d", &gw[i]);

    f(0, 0);

    for(int i=0;i<g;i++){
        if(gw[i]>30*500) printf("%s ", "N");
        else if(dp[c][gw[i]]) printf("%s ", "Y");
        else printf("%s ", "N");
    }
    printf("\n");
}