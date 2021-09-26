#include <cstdio>
int n, s;
int a[21];
int result=0;

void count(int idx, int sum){
    sum+=a[idx];

    if(idx>=n) return;
    if(sum==s) result++;
    
    count(idx+1, sum-a[idx]); // idx+1부터 시작
    count(idx+1, sum); //이전부터 이어져 오고 idx+1까지 이어지는 경우
}

int main(){
    scanf("%d%d", &n ,&s);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);

    count(0, 0);
    printf("%d\n", result);
}