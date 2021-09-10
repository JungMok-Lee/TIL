#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

pair<int, int> dp[1000010]; // first에는 횟수, second에는 그 이전 수

int main(){
    int n;
    scanf("%d", &n);

    dp[0].first=INT_MAX;
    dp[1].first=0;
    dp[1].second=INT_MAX;
    dp[2].first=1;
    dp[2].second=1;

    for(int i=3;i<=n;i++){
        if(i%6==0){
            if(dp[i/2].first<dp[i/3].first){
                dp[i].first=dp[i/2].first+1;
                dp[i].second=i/2;
            }
            else{
                dp[i].first=dp[i/3].first+1;
                dp[i].second=i/3;
            }
        }
        else{
            if(i%2==0){ //3으로는 안나눠지고 2로만 나눠질때
                if(dp[i/2].first<dp[i-1].first){
                    dp[i].first=dp[i/2].first+1;
                    dp[i].second=i/2;
                }
                else{
                    dp[i].first=dp[i-1].first+1;
                    dp[i].second=i-1;
                }
            }
            else if(i%3==0){ //2로는 안나눠지고 3으로만 나눠질 때
                if(dp[i/3].first<dp[i-1].first){
                    dp[i].first=dp[i/3].first+1;
                    dp[i].second=i/3;
                }
                else{
                    dp[i].first=dp[i-1].first+1;
                    dp[i].second=i-1;
                }
            }
            else { //2, 3모두로 다 안나눠질때
                dp[i].first=dp[i-1].first+1;
                dp[i].second=i-1;
            } 
        }
    }
    printf("%d\n%d ", dp[n].first, n);
    while(n!=1){
        if(dp[n].second!=1) printf("%d ",dp[n].second);
        else printf("%d",dp[n].second);
        n=dp[n].second;
    }
    printf("\n");
}