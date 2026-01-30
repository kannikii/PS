#include <iostream>
#include <queue>
#include <vector>
using namespace std;
static int dx[4] = {1, -1, 0, 0};  // 우,좌,하,상
static int dy[4] = {0, 0, 1, -1};  // 우,좌,하,상
static int map[101][101];
static bool visited[101][101] = {
    false,
};
static int N, M, islandNum;
static int parent[101];

typedef struct Edge {
    int s, e, v;
    bool operator>(const Edge& temp) const { return v > temp.v; }
} Edge;

static priority_queue<Edge, vector<Edge>, greater<Edge>> pq;  // 오름차순 정렬
void unionfunc(int a, int b);
int find(int a);
void BFS(int i, int j);
// 섬을 구분하기
// 모든 섬 끼리의 최단 거리 BFS탐색으로 구하기
// 구한 최단 거리가 2이상인 경우 에지 리스트로 삽입
// 에지 리스트로 MST진행
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    // 각 자리에서 BFS탐색을 이용하여 섬을 구분
    // ① 맵 전체를 훑으면서
    // ② 아직 방문하지 않은 땅(1)을 발견하면
    // ③ 거기서 BFS를 시작하고
    // ④ BFS로 상하좌우로 연결된 모든 땅을 하나의 섬으로 묶어
    // ⑤ 그 섬 전체에 같은 번호(islandNum) 를 붙인다
    // ⑥ BFS가 끝나면 islandNum을 +1 하고
    // ⑦ 다시 맵을 훑으면서 이 과정을 반복한다
    islandNum = 2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] != 0 && visited[i][j] != true) {
                BFS(i, j);
                islandNum++;
            }
        }
    }

    // 섬의 각 지점에서 만들 수 있는 모든 에지를 저장
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] >= 2) {   // 섬인 경우 전부 다리를 뻗어본다.
                int s = map[i][j];  // 출발하는 섬 번호

                // 한 방향으로 한 칸 이동
                // 바다면 다리 길이(v) +1 하고 계속 while(바다)
                // 다른 섬 만나면 중단
                // 조건(다리길이>=2 -> 에지 후보, 다리길이<2 -> 버림)
                // 자기 섬 만나면 즉시 중단

                // 4방향으로 다리 시도
                for (int d = 0; d < 4; d++) {
                    int len = 0;  // 다리 길이
                    int y = i;
                    int x = j;

                    while (true) {
                        y += dy[d];
                        x += dx[d];

                        if (y < 0 || x < 0 || y >= N || x >= M) break;
                        if (map[y][x] == 0) {  // 바다면 다리 길이 +1;
                            len++;
                        } else if (map[y][x] == s)
                            break;
                        else {
                            if (len >= 2) {
                                pq.push({s, map[y][x], len});
                            }
                            break;
                        }
                    }
                }
            }
        }
    }

    for (int i = 2; i < islandNum; i++) {
        parent[i] = i;
    }
    int result = 0;
    int usedEdge = 0;

    while (!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();

        int a = cur.s;
        int b = cur.e;
        int cost = cur.v;

        
        if (find(a) != find(b)) {
            unionfunc(a, b);
            result += cost;
            usedEdge++;
        }
    }
    int islandCount = islandNum - 2;
    if (usedEdge != islandCount - 1) {
        cout << -1;
    } else {
        cout << result;
    }

    // 섬 번호 잘 붙었는지 테스트용 출력 코드
    // cout << "\n";
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}

void BFS(int i, int j) {
    queue<pair<int, int>> myQueue;

    myQueue.push({i, j});

    visited[i][j] = true;
    map[i][j] = islandNum;

    while (!myQueue.empty()) {
        int r = myQueue.front().first;
        int c = myQueue.front().second;
        myQueue.pop();

        for (int d = 0; d < 4; d++) {  // 4방향 확인
            int newR = r + dy[d];
            int newC = c + dx[d];
            if (newR < 0 || newC < 0 || newR >= N || newC >= M) continue;

            if (!visited[newR][newC] && map[newR][newC] == 1) {
                visited[newR][newC] = true;
                map[newR][newC] = islandNum;
                myQueue.push({newR, newC});
            }
        }
    }
}
int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void unionfunc(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}
