#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// N개의 값을 3 , 5 로 나누는데 최소한의 수로 나누는 경우의 수 D[];
// D[N] : N kg 을 만드는 최소한의 봉지 수 
// D[0]=0
// D[1]=1, D[2]=1 D[3]=1 D[4]=1 D[5]=1 D[6]=2 D[7]=2 D[8]=2 D[9]=2 
// D[9]는 3L 봉지 3개 가능하나 5L 2개 쓰는게 더 최소이므로 D[9]=2

// 마지막에 선택할 봉투 3L or 5L 둘중 하나
// D[N]=min(D[N-3]+1, D[N-5]+1) 
// D[0]= INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> D(N+1,INT_MAX);
    D[0]=0;
    
    for(int i=1;i<=N;i++){
        if(i>=3 && D[i-3]!=INT_MAX) D[i]=min(D[i],D[i-3]+1);
        if(i>=5 && D[i-5]!=INT_MAX) D[i]=min(D[i],D[i-5]+1);
    }

    if(D[N]==INT_MAX){
        cout<<-1<<"\n";
    }
    else{ cout<<D[N]<<"\n";}

}