#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static vector<vector<int>> adj_list;
static vector<bool> visited;
static vector<int> order;
static int cnt=0;
void DFS(int start);
int main() {

    int N,M,R;
    cin>>N>>M>>R;
    adj_list.resize(N+1);
    visited=vector<bool>(N+1,false);
    order=vector<int>(N+1,0);
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    for(int i=1;i<=N;i++){
        sort(adj_list[i].begin(),adj_list[i].end(),greater<int>());
    }
    
    DFS(R);
    for(int i=1;i<=N;i++){
        cout<<order[i]<<"\n";
    }
}
void DFS(int start){
    visited[start]=true;
    cnt++;
    order[start]=cnt;
    for(int i: adj_list[start]){
        if(!visited[i]){
            DFS(i);
        }
    }
}