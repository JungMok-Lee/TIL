#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

/*
    탱자탱자 놀다가 이해 안하고 했다. 이렇게 커밋하면 무슨 소용인가 싶기도 하다.
    이 주석 꼭 내일이던 언제던 바꾸기.
*/
int dp[101];

int main(){
    int n;
    vector<vector<int> > line;
    vector<int> a;
    vector<int> dp;

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        vector<int> v;
        int a,b;
        scanf("%d%d", &a, &b);
        v.push_back(a);
        v.push_back(b);
        line.push_back(v);
    }

    sort(line.begin(), line.end());

    for(int i=0;i<n;i++){
        dp.push_back(1);
        a.push_back(line[i][1]);
    }

    dp[0]=1;
    for(int i=1;i<n;i++){
        for(int j=i;j>=0;j--){
            if(a[i]>a[j] && dp[i]<=dp[j]) dp[i]=dp[j]+1;
        }
    }
    
    int max=0;
    for(int i=0;i<n;i++) max=std::max(max, dp[i]);

    printf("%d\n", dp.size()-max);
}