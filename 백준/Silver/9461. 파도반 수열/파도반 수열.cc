#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin>>T;


	// 1, 1, 1, (1+1), (1+1+0), (2+1), (3+1), (4+1), (5+2), (7+2)
	// (9+3),(9+3+4),(9+3+4+5),(9+3+4+5+7),()
	long long dp[101];
	dp[0]=0;
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	dp[4]=2;
	dp[5]=2;
	dp[6]=dp[5]+dp[6-5];
	// dp[n]=dp[n-1]+dp[n-5];
	for(int i=6;i<101;i++){
		dp[i]=dp[i-1]+dp[i-5];
	}

	while(T--){
		int N;
		cin>>N;

		cout<<dp[N]<<"\n";
	}
	return 0;
}