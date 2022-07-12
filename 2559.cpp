#include <cstdio>

long long n, k;
int t[100001];

int main(){
    scanf("%lld%lld", &n, &k);
    for(int i=0;i<n;i++) scanf("%d", &t[i]);

    long long sum=0;
    for(int i=0;i<k;i++) sum+=t[i];

    long long max=sum;
    long long s=sum;
    for(int i=k;i<n;i++){
        s=(s+t[i])-t[i-k];
        if(s>max) max=s;
    }
    printf("%lld\n", max);
}