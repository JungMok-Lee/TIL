#include <cstdio>
int main(){
	int dp[41];

	dp[0]=0;
	dp[1]=1;
	dp[2]=1;

	/* 처음에는 2차원 배열로 만들어서 dp[n][0]에는 0 개수, dp[n][1]에는 1 개수를 담았는데 힌트를 보니까 그럴 필요가 없었다.
	   그냥 dp[n-1]에는 0의 개수, dp[n]에는 1의 개수가 담겨 있다
	   그래서 결국 피보나치 함수 dp 문제와 풀이가 똑같아진다.
	*/
	for(int i=3;i<41;i++) dp[i]=dp[i-1]+dp[i-2]; 

	int t,n;
	scanf("%d",&t);

	while(t--){
		scanf("%d",&n);
		if(n==0) printf("1 0\n");
		else if(n==1) printf("0 1\n");
		else printf("%d %d\n",dp[n-1], dp[n]);
	}
}
