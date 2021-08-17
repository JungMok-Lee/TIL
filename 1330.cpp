#include <cstdio>
/*
바쁘지도 않았으면서 이런 거 푸는 게 어딨냐. 분발하자.
*/
int main(){
    int a, b;
    scanf("%d%d", &a, &b);

    if(a>b) printf(">\n");
    else if(a<b) printf("<\n");
    else printf("==\n");
}