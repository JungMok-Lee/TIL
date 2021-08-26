#include <cstdio>
#include <utility> //pair을 위해 사용
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int n;
    std::pair<int, int> mat[510];
    int dp[510][510]; // dp[i][j] : i에서 시작하여 j에서 끝나는 최소 계산 수
    scanf("%d", &n);

    for(int i=1;i<=n;i++){
        int r, c;
        scanf("%d%d", &r, &c);
        mat[i].first=r;
        mat[i].second=c;
    }
    // 파일 합치기 문제와 굉장히 비슷함.
    // 이것도 순서대로 합쳐야 하기 때문에 첫번째 행렬, 다섯번째 행렬 이렇게 골라서 합치는 것이 불가능.
    // for문으로 흝으면서 중간에 mid로 두 개로 나누고, 최소가 되는 mid를 찾으면 됨. 그 사이에 행렬 세개가 곱해지므로 mat[tx].first*mat[mid].second*mat[ty].second를 곱하면 된다.
    for(int i=1;i<n;i++){ // i는 시작점과 끝점의 차이
        for(int tx=1;tx+i<=n;tx++){
            int ty=tx+i;
            dp[tx][ty]=INT_MAX;
            for(int mid=tx;mid<=ty;mid++) dp[tx][ty]=std::min(dp[tx][ty], dp[tx][mid]+dp[mid+1][ty]+mat[tx].first*mat[mid].second*mat[ty].second);
        }
    }
    printf("%d", dp[1][n]);

}