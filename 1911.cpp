#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct _p{
    int s,e;
}p;

bool cmp(p &i1, p &i2){
    if(i1.s==i2.s) return i1.e<i2.e;
    return i1.s<i2.s;
}
int main(){
    int n, l;
    p m[10001];
    scanf("%d%d", &n, &l);
    for(int i=0;i<n;i++){
        scanf("%d%d", &m[i].s, &m[i].e);
    }  
    sort(m, m+n, cmp);

    int end=0;
    int ans=0;

    for(int i=0;i<n;i++){
        int x=m[i].s;
        int y=m[i].e;
        if(x<end) x=end;
        if(x<y){
            int c=(y-x)/l;
            if((y-x)%l!=0) c++;

            end=x+c*l;
            ans+=c;
        }
    }

    printf("%d\n", ans);


}