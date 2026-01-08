#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
static int N, M, V;
static vector<vector<int>> adj_link;
static vector<bool> visited;
void DFS(int node);
void BFS(int node);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;

    adj_link.resize(N+1);
    visited = vector<bool>(N + 1, false);
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        adj_link[s].push_back(e);
        adj_link[e].push_back(s);
    }

    for(int i=1;i<N+1;i++){
        sort(adj_link[i].begin(),adj_link[i].end());
    }

    DFS(V);
    cout << "\n";

    // 방문 배열 초기화
    for (int i = 0; i < visited.size(); i++) {
        visited[i] = false;
    }

    BFS(V);
    cout << "\n";
}

void DFS(int node) {
    cout << node << " ";
    visited[node] = true;

    // adj_link[node]속의 배열들을 반복하여 탐색해야함
    for (int i : adj_link[node]) {
        if (visited[i] == false) {
            DFS(i);
        }
    }
}

void BFS(int node) {
    queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;

    while (!myqueue.empty()) {
        int now_node = myqueue.front();
        myqueue.pop();
        cout << now_node << " ";
        for (int i : adj_link[now_node]) {
            if (visited[i] == false) {
                visited[i] = true;
                myqueue.push(i);
            }
        }
    }
}