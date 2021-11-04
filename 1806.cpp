#include <cstdio>
#include <algorithm>
using namespace std;

int n,s;
int a[100010];

int main(){
    scanf("%d%d", &n, &s);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);

    int length=100010;
    int en=0;
    int sum=a[0];
    for(int st=0;st<n;st++){
        while(en<n && sum<s) {
            en++;
            if(en!=n) sum+=a[en];
        }
        if(en==n) break;
        length=(en-st+1<length)?en-st+1:length;
        sum-=a[st]; // st를 앞으로 옮기는 과정
    }
    if(length!=100010) printf("%d\n", length);
    else printf("0\n");
}