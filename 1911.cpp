#include <cstdio>
#include <algorithm>
using namespace std;

struct p{
    int a, b;
};

bool cmp(p &f, p &s){
    if(f.a==s.a) return f.b<s.b;
    return f.a<s.a;
}
p se[10005];

int main(){
    int n, l;
    scanf("%d%d", &n, &l);

    for(int i=0;i<n;i++){
        scanf("%d%d", &se[i].a, &se[i].b);
    }

    sort(se, se+n, cmp);

    int ans=0, s=0;
    for(int i=0;i<n;i++){
        int x=se[i].a;
        int y=se[i].b;
        if(x<s) x=s;

        if(x<y){
            int cnt=(y-x)/l;
            if((y-x)%l!=0) cnt++;

            ans+=cnt;
            s=x+l*cnt;
        }
    }
    printf("%d\n",ans);
}