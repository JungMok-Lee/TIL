#include <cstdio>

int a[100001];

int main(){
    int n, s;
    scanf("%d%d", &n, &s);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);

    int l=0, r=0;
    int sum=a[0];
    int len=100001;

    while(l<n && r<n && l<=r){
        if(sum<s){
            r++;
            sum+=a[r];
            //printf("added, l:%d, r:%d, sum=%d\n", l, r, sum);
        }
        else{
            if(len>r-l+1) len=r-l+1;
            sum-=a[l];
            l++;
            //printf("sub, l:%d, r:%d, sum=%d\n", l,r,sum);
        }
    }
    
    if(len!=100001) printf("%d\n", len);
    else printf("%d\n", 0);
}

// 1 2 3 5 5 7 8 9 10
// 15 만들기
// 