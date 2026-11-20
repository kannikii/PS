#include <iostream>
#include <vector> 

using namespace std;

int n, m;
int from[10000], to[10000];
vector<vector<int>> graph;
vector<bool> visited;
int cnt=0;
void dfs(int vertex) {
    for(int i=0;i<graph[vertex].size();i++){
        if(!visited[i] && graph[vertex][i]==1){
            visited[i]=true;
            cnt++;
            dfs(i);
        }
    }
    
}
int main() {
    cin >> n >> m;
     // 인접 그래프
    graph=vector<vector<int>>(n+1, vector<int>(n+1, 0));
    visited=vector<bool> (n+1,false);
    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
        graph[from[i]][to[i]]=1;
        graph[to[i]][from[i]]=1;
    }

    visited[1]=true;
    dfs(1);

    cout<<cnt;

    

    return 0;
}
