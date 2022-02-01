#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct _p{
    int s, e;
}p;

bool cmp(p &f, p&s){
    if(f.e==s.e) return f.s<s.s;
    return f.e<s.e;
}


int main(){
    int N;
    p I[100001];

    scanf("%d", &N);
    for(int i=0;i<N;i++) scanf("%d%d", &I[i].s, &I[i].e);

    sort(I, I+N, cmp);

    int c_end=0;
    int ans=0;
    for(int i=0;i<N;i++){
        if(I[i].s<c_end) continue;
        
        c_end=I[i].e;
        ans++;
    }

    printf("%d\n", ans);

}