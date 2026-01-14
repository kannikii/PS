#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
static int N, M, R;
static vector<vector<int>> adj_list;
static vector<bool> visited;
static queue<int> myQueue;
static vector<int> order;
static int cnt=0;
void BFS(int node);
int main() {
    cin >> N >> M >> R;
    adj_list.resize(N + 1);
    visited = vector<bool>(N + 1, false);
    order = vector<int>(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    for(int i=1;i<=N;i++){
        sort(adj_list[i].begin(),adj_list[i].end(),greater<int>());
    }
    BFS(R);
    for(int i=1;i<=N;i++){
        cout<<order[i]<<"\n";
    }
}

void BFS(int node) {
    visited[node] = true;
    myQueue.push(node);
    cnt++;
    order[node]=cnt;
    while (!myQueue.empty()) {
        int cur = myQueue.front();
        myQueue.pop();

        for (int next : adj_list[cur]) {
            if (!visited[next]) {
                myQueue.push(next);
                visited[next] = true;
                cnt++;
                order[next]=cnt;
            }
        }
    }
}