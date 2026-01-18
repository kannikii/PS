#include <iostream>
#include <queue>
#include <vector>

using namespace std;
static vector<int> D;
static vector<vector<int>> adj_list;
int main(){
    int N,M;
    cin>>N>>M;
    adj_list.resize(N+1);
    D.resize(N+1);
    for(int i=0;i<M;i++){
        int A,B;
        cin>>A>>B;
        adj_list[A].push_back(B);
    }
    for(int i=1;i<=N;i++){
        for(int j: adj_list[i]){
            D[j]++;
        }
    }

    queue<int> myQueue;
    int cnt=0;
    vector<int> dist(N+1,0);
    for(int i=1;i<=N;i++){
        if(D[i]==0){
            myQueue.push(i);
            dist[i]++;
        }
    }

    while(!myQueue.empty()){
        int now=myQueue.front();
        myQueue.pop();
        
        for(int next: adj_list[now]){
            D[next]--;
            if(D[next]==0){
                myQueue.push(next);
                dist[next]=dist[now]+1;
            }
        }
    }
    for(int i=1;i<=N;i++){
        cout<<dist[i]<<" ";
    }
    cout<<"\n";
}