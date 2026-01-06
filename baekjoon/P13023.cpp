#include <iostream>
#include <vector>

using namespace std;

static bool arrive = false;
static vector<vector<int>> adj_list;
static vector<bool> visited(false);
void DFS(int now, int depth);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    adj_list.resize(N);
    visited = vector<bool>(N, false);

    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        adj_list[s].push_back(e);
        adj_list[e].push_back(s);
    }

    for (int i = 0; i < N; i++) {
        DFS(i, 1);
        if (arrive) {
            break;
        }
    }

    if (arrive) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }
}

void DFS(int now, int depth) {
    if (depth == 5 || arrive) {
        arrive = true;
        return;
    }

    if (visited[now]) {
        return;
    }
    visited[now] = true;

    for (int i : adj_list[now]) {
        if (visited[i] == false) {
            DFS(i,depth+1);
            // 호출 마다 깊이 1씩 증가
        }
    }
    visited[now]=false;
}