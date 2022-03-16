#include <cstdio>


int main(){
    long long int as, bs;
    scanf("%lld %lld", &as, &bs);

    long long a[as], b[bs];
    for(long long int i=0;i<as;i++) scanf("%lld", &a[i]);
    for(long long int i=0;i<bs;i++) scanf("%lld", &b[i]);

    long long int c[as+bs];
    long long int ap=0, bp=0;

    while(ap<as || bp<bs){
        if(ap==as){
            c[ap+bp]=b[bp];
            bp++;
        }
        else if(bp==bs){
            c[ap+bp]=a[ap];
            ap++;
        }

        else if(a[ap]<b[bp]){
            c[ap+bp]=a[ap];
            ap++;
        }
        else{
            c[ap+bp]=b[bp];
            bp++;
        }
    }
    
    for(long long int i=0;i<as+bs;i++) printf("%lld ", c[i]);
}