#include <iostream>
#include <vector>
#include <queue>

using namespace std;
static vector<vector<int>> A;
static vector<bool> visited;
static vector<int> parent;
static queue<int> myQueue;
void BFS(int node);
int main () {
    int N;
    cin>> N;
    A.resize(N+1);
    parent.resize(N+1);
    visited=vector<bool>(N+1,false);
    parent = vector<int>(N+1, 0);

    for(int i=0;i<N-1;i++){
        int u,v;
        cin>>u>>v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    //인접리스트

    BFS(1);
    for(int i=2;i<=N;i++){
        cout<<parent[i]<<"\n";
    }
}

void BFS(int node){
    myQueue.push(node);
    visited[node]=true;
    while(!myQueue.empty()){
        int now=myQueue.front();
        myQueue.pop();
        
        for(int next:A[now]){
            if(!visited[next]){
                myQueue.push(next);
                visited[next]=true;
                parent[next]=now;
            }
        }
    }
}