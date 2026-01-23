#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> edge;
static vector<vector<edge>> A;
static vector<vector<edge>> reverseA;
static vector<int> distFromX;
static vector<int> distToX;
void dijkstra(int start, vector<vector<edge>>& graph, vector<int>& dist);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, X;
    cin >> N >> M >> X;  // N명의 학생이 X번 마을에가는 M가지 도로가 있다.
    A.resize(N + 1);
    reverseA.resize(N + 1);
    for (int i = 1; i <= M; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        A[s].push_back({t, e});
        reverseA[e].push_back({t, s});
    }

    // 최단 거리 배열 초기화
    distFromX.resize(N + 1);
    fill(distFromX.begin(), distFromX.end(), INT_MAX);
    distToX.resize(N + 1);
    fill(distToX.begin(), distToX.end(), INT_MAX);

    // X->i 각자 집으로 돌아가는 경로
    distFromX[X] = 0;
    dijkstra(X, A, distFromX);
    // i->X 파티에 가는 경로 (각자 집이 다르므로 출발지i마다 다익스트라를 할 수 없어서 역방향 경로로 수행)
    distToX[X] = 0;
    dijkstra(X, reverseA, distToX);

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        answer = max(answer, distFromX[i] + distToX[i]);
    }

    cout << answer << "\n";
}

void dijkstra(int start, vector<vector<edge>>& graph, vector<int>& dist) {
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [nowDist, nowNode] = pq.top();
        pq.pop();

        if (nowDist > dist[nowNode]) continue;

        for (auto [nextDist, nextNode] : graph[nowNode]) {
            if (dist[nextNode] > dist[nowNode] + nextDist) {
                dist[nextNode] = dist[nowNode] + nextDist;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
}