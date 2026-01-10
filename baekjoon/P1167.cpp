#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> edge;
static vector<vector<edge>> A;
static vector<bool> visited;
static vector<int> m_distance;
static queue<int> myQueue;
void BFS(int index);

int main() {
    int N;
    cin >> N;
    A.resize(N + 1);

    for (int i = 0; i < N; i++) {
        int S;
        cin >> S;
        while (true) {
            int E, V;
            cin >> E;
            if (E == -1) break;
            cin >> V;
            A[S].push_back(edge(E, V));
        }
    }
    m_distance = vector<int>(N + 1, 0);
    visited = vector<bool>(N + 1, false);
    BFS(1);
    int farNode = 1;
    for (int i = 1; i <= N; i++) {
        if (m_distance[i] > m_distance[farNode]) farNode = i;
    }

    // 초기화
    fill(visited.begin(), visited.end(), false);
    fill(m_distance.begin(), m_distance.end(), 0);
    while (!myQueue.empty()) myQueue.pop();

    // 2차 BFS
    BFS(farNode);

    // m_distance 벡터에서 최댓값 찾아 출력
    int answer = *max_element(m_distance.begin(), m_distance.end());
    cout << answer << '\n';
}

void BFS(int index) {
    myQueue.push(index);
    visited[index] = true;

    while (!myQueue.empty()) {
        int now_node = myQueue.front();
        myQueue.pop();
        for (edge i : A[now_node]) {
            if (!visited[i.first]) {
                myQueue.push(i.first);
                visited[i.first] = true;
                m_distance[i.first] = m_distance[now_node] + i.second;
            }
        }
    }
}