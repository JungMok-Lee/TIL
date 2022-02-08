#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n,x;
    int a[100001];

    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    sort(a, a+n);
    scanf("%d", &x);

    int s=0,e=n-1;
    int ans=0;

    while(1){
        if(s>=e) break;
        int sum = a[s]+a[e];

        if(sum==x) {
            ans++;
            s++;
            e--;
        }

        else if(sum<x) s++;
        else e--;
    }
    printf("%d\n", ans);
}