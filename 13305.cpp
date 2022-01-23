#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);
    unsigned long long r[100001]; 
    unsigned long long h[100001];
    for(int i=0;i<n-1;i++) scanf("%llu", &r[i]);
    for(int i=0;i<n;i++) scanf("%llu", &h[i]);

    unsigned long long sum=0, min=1000000000;
    for(int i=0;i<n;i++){ //h 기준 iter
        if(h[i]<min){
            min=h[i];
        }
        sum+=min*r[i];
    }

    printf("%llu\n", sum);
}