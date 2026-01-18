#include <iostream>
#include <queue>
#include <vector>

using namespace std;
static vector<vector<int>> adj_list;
static vector<int> D;
int main() {
    int N, M;
    cin >> N >> M;
    D.resize(N + 1);
    adj_list.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj_list[A].push_back(B);
    }
    for (int i = 1; i <= N; i++) {
        for (int j : adj_list[i]) {
            D[j]++;
        }
    }
    priority_queue<int,vector<int>,greater<int>> myQueue;
    for(int i=1;i<=N;i++){
        if(D[i]==0){
            myQueue.push(i);
        }
    }
    while(!myQueue.empty()){
        int now=myQueue.top();
        myQueue.pop();
        cout<<now<<" ";
        for(int next:adj_list[now]){
            D[next]--;
            if(D[next]==0){
                myQueue.push(next);
            }
            
        }
    }
    cout<<"\n";
}