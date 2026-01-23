#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
static int N, E;
typedef pair<int, int> edge;
static vector<vector<edge>> A;
vector<int> dijkstra(int start);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> E;
    A.resize(N + 1);

    for (int i = 1; i <= E; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        A[a].push_back({c, b});
        A[b].push_back({c, a});
    }
    int v1, v2;
    cin >> v1 >> v2;

    // dist1,distV1,distV2 초기화
    // 다익스트라 함수 안에서 각각 해도되나?

    vector<int> dist1 = dijkstra(1);
    vector<int> distV1 = dijkstra(v1);
    vector<int> distV2 = dijkstra(v2);

    // 두가지 경우의 수 경로 조합
    // 1. 1->v1 + v1->v2 + v2->N
    // 2. 1->v2 + v2->v1 + v1->N
    // 둘중 작은 수를 가지는 값 출력
    // 경로 없으면 -1 출력

    // 다익스트라 합은 기본적으로 오버플로우 우려가 있으므로 long long 자료형 사용
    long long INF = (long long)INT_MAX * 3;  // 3개 전부 INT_MAX일때의 최댓값
    long long path1 = INF;
    long long path2 = INF;
    // 1. 1->v1 + v1->v2 + v2->N
    if (dist1[v1] != INT_MAX && distV1[v2] != INT_MAX && distV2[N] != INT_MAX) {
        path1 = (long long)dist1[v1] + distV1[v2] + distV2[N];
    }
    // 2. 1->v2 + v2->v1 + v1->N
    if (dist1[v2] != INT_MAX && distV1[N] != INT_MAX && distV2[v1] != INT_MAX) {
        path2 = (long long)dist1[v2] + distV1[N] + distV2[v1];
    }
    long long answer = min(path1,path2);
    if(answer==INF){
        cout<<-1<<"\n";
    }else{
        cout<<answer<<"\n";
    }
}

vector<int> dijkstra(int start) {  // dist배열 계산해서 반환
    vector<int> dist(N + 1);
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[start] = 0;

    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [nowDist, nowNode] = pq.top();
        pq.pop();

        // dist[] 값은 이미 저장된 값, nowDist는 큐에 들어있는값
        // 중복 연산 방지 visited역할, 이미 들어있는값이 더 작으면 넘어간다.
        if (nowDist > dist[nowNode]) continue; 
        
        for (auto [nextDist, nextNode] : A[nowNode]) {
            if (dist[nextNode] > dist[nowNode] + nextDist) {
                dist[nextNode] = dist[nowNode] + nextDist;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
    return dist;
}