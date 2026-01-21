#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> edge;

// 인접 리스트
static vector<vector<edge>> A;

// 다익스트라용 우선순위 큐 (min-heap)
// (현재까지 비용, 노드)
static priority_queue<edge, vector<edge>, greater<edge>> myQueue;

// 각 노드별 K개의 최단 경로 비용 저장용 힙 (max-heap)
// K개가 차면 가장 큰 값부터 교체됨
static vector<priority_queue<int>> heap;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    A.resize(N + 1);

    // 그래프 입력
    for (int i = 1; i <= M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        A[a].push_back({c, b});  // (가중치, 도착 노드)
    }

    // 일반적인 최단경로 (다익스트라)
    // 다익스트라에선 필요한 값(저장해야하는 값) 1개 뿐 - 최단경로
    // visit, dp, dist 등에 값을 저장하고 갱신을 함

    // 그러나 이 문제는 K번째 최단 경로를 구하고자 함.
    // K번째 -> 값이 K개, 순서(정렬)
    // K개의 값을 저장할 필요가 있고, 그 순서를 정렬할 필요가 있음
    // vector, priority_queue (heap)

    heap.resize(N + 1);

    // 시작 노드 초기화
    myQueue.push({0, 1});
    heap[1].push(0);

    // K번째 최단 경로 탐색
    while (!myQueue.empty()) {
        int nowNode = myQueue.top().second;
        int nowCost = myQueue.top().first;
        myQueue.pop();

        for (auto it : A[nowNode]) {
            int nextNode = it.second;
            int nextCost = nowCost + it.first;

            // 아직 K개가 안 찼으면 그냥 추가
            if (heap[nextNode].size() < K) {
                heap[nextNode].push(nextCost);
                myQueue.push({nextCost, nextNode});
            }
            // K개가 다 찼고, 더 짧은 경로라면 교체
            else if (heap[nextNode].top() > nextCost) {
                heap[nextNode].pop();
                heap[nextNode].push(nextCost);
                myQueue.push({nextCost, nextNode});
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= N; i++) {
        if (heap[i].size() < K)
            cout << -1 << "\n";
        else
            cout << heap[i].top() << "\n";  // K번째 최단거리
    }
}
