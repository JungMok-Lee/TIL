#include <cstdio>
int n, m;
int lst[10];
bool is_used[10];

void func(int k){
    if(k==m){ // 끝까지 다 돌았으면 출력
        for(int i=0;i<m;i++) printf("%d ", lst[i]);
        printf("\n");
        return;
    }

    for(int i=1;i<=n;i++){
        if(!is_used[i]){
            lst[k]=i;
            is_used[i]=1; // i번째 사용 했다고 표시
            func(k+1); // 재귀 문제
            is_used[i]=0; // i번째 사용 해제
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    func(0);
}    
