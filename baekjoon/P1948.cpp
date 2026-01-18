#include <iostream>
#include <queue>
#include <vector>
using namespace std;
static vector<vector<pair<int, int>>> reverseA;
static vector<vector<pair<int, int>>> A;
static int D[10001];
int main() {
    int N, M;
    cin >> N;
    A.resize(N + 1);
    reverseA.resize(N + 1);

    cin >> M;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back({v, w});
        // 역 위상 정렬 위한 역 방향 인접리스트 저장
        reverseA[v].push_back({u, w});
    }
    int start, end;
    cin >> start >> end;
    // 진입 차수 배열 초기화
    for (int i = 1; i <= N; i++) {
        for (pair<int,int> next: A[i]) {
            D[next.first]++;
        }
    }
    // 위상 정렬 수행
    queue<int> myQueue;
    // 진입 차수가 0인 노드 큐에 삽입 하면서 시작
    // for(int i=1;i<=N;i++){
    //     if(D[i]==0){
    //         myQueue.push(i);
    //     }
    // }

    // 그런데 여기선 시작점이 주어지므로 시작점을 큐에 넣고 시작
    myQueue.push(start);
    vector<int> dist(N + 1);  // 도착 도시 별 소요시간 배열
    while (!myQueue.empty()) {
        int now = myQueue.front();
        myQueue.pop();
        for (pair<int, int> next : A[now]) {
            dist[next.first] =
                max(dist[next.first],
                    dist[now] + next.second);  // 도착 도시 별 소요시간 갱신
            D[next.first]--;
            if (D[next.first] == 0) {
                myQueue.push(next.first);
            }
        }
    }

    // 역 위상 정렬 수행 (간선 역추적을 위해 진행)
    int distCnt = 0;
    vector<bool> visited;
    visited.resize(N + 1);

    queue<int> rqueue;
    rqueue.push(end);
    visited[end] = true;

    while (!rqueue.empty()) {
        int now = rqueue.front();
        rqueue.pop();
        for (pair<int, int> next : reverseA[now]) {
            if (dist[now] == dist[next.first] + next.second) {
                distCnt++;
                if (!visited[next.first]) {
                    rqueue.push(next.first);
                    visited[next.first] = true;
                }
            }
        }
    }

    // 가장 오래 걸리는 길의 시간 출력
    cout << dist[end] << "\n";
    // 가장 오래 걸리는 경로의 간선의 개수를 출력 (역추적)
    cout << distCnt << "\n";
}

// 위상 정렬을 통해 길의 순서를 만들어 놓고
// 그 순서대로 덧셈을 하며 경로별 소요시간을 계산하며
// 최장 소요시간인 경로를 갱신해가며 진행
// 전부 탐색한 뒤 최종 최장 소요시간을 출력하고
// 가장 오래 걸리는 경로의 간선의 개수를 출력
