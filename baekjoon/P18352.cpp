#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
static int N, M, K, X;
static vector<vector<int>> adj_list;
static vector<int> visited;
static queue<int> myQueue;
void BFS(int node);
int main() {
    cin >> N >> M >> K >> X;
    adj_list.resize(N + 1);
    visited = vector<int>(N + 1, -1);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj_list[A].push_back(B);
    }

    BFS(X);
    vector<int> answer;
    for (int i = 0; i <= N; i++) {
        if (visited[i] == K) {
            answer.push_back(i);
        }
    }
    if (answer.empty()) {
        cout << -1 << "\n";
    } else {
        sort(answer.begin(), answer.end());
        for (int i : answer) {
            cout << i << "\n";
        }
    }
}
void BFS(int node) {
    myQueue.push(node);
    visited[node] = 0;

    while (!myQueue.empty()) {
        int cur = myQueue.front();
        myQueue.pop();

        for (int i : adj_list[cur]) {
            if (visited[i] == -1) {
                visited[i] = visited[cur] + 1;
                myQueue.push(i);
            }
        }
    }
}