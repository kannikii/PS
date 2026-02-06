#include <iostream>

using namespace std;
static long long mod = 1000000007;
static long long dp[2501];

int main() {
    // 카탈란 수 DP 전처리
    dp[0]=1;
    for(int n=1;n<=2500;n++){
        for(int i=0;i<n;i++){
            dp[n]=(dp[n]+dp[i]*dp[n-1-i])%mod;
        }
    }
    int T;
    cin>>T;
    while(T--){
        int L;
        cin>>L;
        if(L%2!=0){
            cout<<"0"<<"\n";
        }else{
            cout << dp[L / 2]<<"\n";
        }
    }
}
