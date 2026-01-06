#include <iostream>
#include <vector>

using namespace std;
//인접리스트
static vector<vector<int>> adj_list;
//방문배열
static vector<bool> visited(false);
//DFS
void DFS(int v);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin>>N>>M;
    adj_list.resize(N+1);
    visited=vector<bool>(N+1,false);

    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);   //무방향 그래프라 양쪽 다 넣어줘야함
    }

    int count=0;

    for(int i=1;i<N+1;i++){
        if(!visited[i]){    //방문하지 않은 노드 없을때 까지 반복
            count++;
            DFS(i);//i번째 노드 탐색
        }
    }
    cout<<count<<"\n";
}

void DFS(int v) {
    if(visited[v]){
        return;
    }
    visited[v]=true;

    for(int i:adj_list[v]){
        if(visited[i]==false){
            DFS(i);
        }
    }
}