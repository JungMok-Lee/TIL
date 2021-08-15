#include <cstdio>
int main(){
    /*
        dp 문제도 못 풀고...
        쉬운 소수 문제 푼다고 가져 왔는데도
        제대로 못 풀고 답지 확인..
        답지 참고해서 겨우 해냄...
    */
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    int count=0;
    int ncount=0;
    int result=0, minnumber=-1;

    for(int i=m;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(i%j==0) count++;
        }
        if(count==2){
            ncount++;
            result+=i;
            if(ncount==1) minnumber=i;
        }
        count=0;
        
    }
    if(ncount) printf("%d\n%d\n", result, minnumber);
    else printf("%d\n",-1);
}