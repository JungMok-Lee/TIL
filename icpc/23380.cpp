#include <cstdio>
#include <algorithm>
using namespace std;

int b[1000001];
int p[1000001];

pair<int, int> bp[1000001];

int main(){
    int n;
    scanf("%d", &n);

    int bsum=0, psum=0;
    for(int i=0;i<n;i++){
        scanf("%d%d", &b[i], &p[i]);
        bsum+=b[i];
        psum+=p[i];
        bp[i].first=b[i];
        bp[i].second=p[i];
    }

    if(bsum%(n/2)||psum%(n/2)){
        printf("impossible\n");
        return 0;
    }

    bsum/=(n/2);
    psum/=(n/2);
    sort(bp, bp+n);

    for(int i=0;i<n/2;i++){

        int bb=b[i] + b[n-1-i];
        int pp=p[i] + p[n-1-i];

        if(bb!=bsum){
            printf("impossible\n");
            return 0;
        }
        if(pp!=psum){
            printf("impossible\n");
            return 0;
        }
    }

    printf("possible\n");
}