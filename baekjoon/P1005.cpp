#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;
    
    for(int i=0;i<T;i++){
        int N,K;
        cin>> N>>K;
        vector<vector<int>> A;
        A.resize(N+1);
        vector<int> structTime(N+1,0);
        for(int j=1;j<=N;j++){
            cin>>structTime[j];
        }
        for(int k=0;k<K;k++){
            int X,Y;
            cin>>X>>Y;
            A[X].push_back(Y);
        }
        int W;
        cin>>W;
        // dp[W]출력
        // 위상 정렬 + dp로 소요시간 계산
        vector<int> D(N+1,0);
        for(int l=1;l<=N;l++){
            for(int next:A[l]){
                D[next]++;
            }
        }
        queue<int> myQueue;
        vector<int> dp(N+1,0);
        for(int m=1;m<=N;m++){
            if(D[m]==0){
                myQueue.push(m);
                dp[m]=structTime[m];
            }
        }
        while(!myQueue.empty()){
            int now=myQueue.front();
            myQueue.pop();
            
            for(int next: A[now]){
                dp[next]=max(dp[next],dp[now]+structTime[next]);
                D[next]--;
                if(D[next]==0){
                    myQueue.push(next);
                    
                }
            }
        }

        cout<<dp[W]<<"\n";
    }
}