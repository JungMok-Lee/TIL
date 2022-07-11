#include <cstdio>

int cn;
int chu[31];
int bn;
int b[8];

bool dp[31][50000]={false, }; // dp[i][j] : i번째까지 담아서 j무게를 만들 수 있는가?

void f(int i, int w){
    if(i>cn) return;
    if(w>40000) return;
    if(dp[i][w]) return;

    dp[i][w]=true;

    f(i+1, w+chu[i]);
    f(i+1, w);
    if (w-chu[i]>=0) f(i+1, w-chu[i]);
    else f(i+1, chu[i]-w);
}

int main(){
    scanf("%d", &cn);
    for(int i=0;i<cn;i++) scanf("%d", &chu[i]);
    int bn;
    scanf("%d", &bn);
    for(int i=0;i<bn;i++) scanf("%d", &b[i]);

    f(0,0);

    for(int i=0;i<bn;i++){
        if(b[i]>15000) printf("%s ", "N");
        else if(dp[cn][b[i]]) printf("%s ", "Y");
        else printf("%s ", "N");
    }
    printf("\n");
    
}