#include <cstdio>
#include <map>
using namespace std;

map<pair<long, long>, long> m;
pair<long long, long long> bp[10000001];


int main(){
    int n;
    scanf("%d", &n);

    int bsum=0, psum=0;
    for(int i=0;i<n;i++){
        int b, p;
        scanf("%d%d", &b, &p);
        bp[i] = {b, p};
        m[bp[i]]++;
        bsum+=b;
        psum+=p;
    }

    if(bsum%(n/2)||psum%(n/2)){
        printf("impossible\n");
    }

    long long mb = bsum/(n/2);
    long long mp = psum/(n/2);

    for(int i=0;i<n;i++){
        if(!m[bp[i]]) continue; // 이미 매칭 됐으면 하지마

        pair<long, long> target = {mb-bp[i].x, mp-bp[i].y};
        if(!m[target]){
            printf("impossible");
            return 0;
        }

    }


}