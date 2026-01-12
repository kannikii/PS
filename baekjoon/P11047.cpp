#include <iostream>
#include <vector>

using namespace std;
static vector<int> coin;
int main (){
    int N,K;
    cin >>N>>K;
    coin=vector<int>(N+1);
    for(int i=0;i<N;i++){
        cin>>coin[i];
    }
    int cnt=0;

    while(K!=0){
        for(int i=N-1;i>=0;i--){
            if(coin[i]<=K){
                cnt+=K/coin[i];
                K=K%coin[i];
            }
        }
    }
    cout<<cnt<<"\n";
}
