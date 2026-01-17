#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
static int dx[4] = {1, -1, 0, 0};
static int dy[4] = {0, 0, 1, -1};
static int mp[1001][1001];
static int dist[1001][1001][2];
// dist[y][x][0] : (y,x)에 벽을 안 부수고 도착
// dist[y][x][1] : (y,x)에 벽을 부수고 도착
static int N, M;
static queue<tuple<int, int, int>> myQueue;
void BFS(int y, int x);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            mp[i][j] = line[j] - '0';
        }
    }
    // [0][0]->[N-1][M-1] 까지의 최단거리 출력
    BFS(0, 0);
    // 벽을 부수고 간 거리와, 부수지 않고 간 거리 중 더 작은 값을 최단거리로
    // 출력
    int a = dist[N - 1][M - 1][0];
    int b = dist[N - 1][M - 1][1];

    if (a == 0 && b == 0)
        cout << -1;
    else if (a == 0)
        cout << b;
    else if (b == 0)
        cout << a;
    else
        cout << min(a, b);
}
void BFS(int y, int x) {
    myQueue.push({y, x, 0});
    dist[y][x][0] = 1;
    while (!myQueue.empty()) {
        auto [curY, curX, wall] = myQueue.front();
        myQueue.pop();

        for (int i = 0; i < 4; i++) {
            int newY = curY + dy[i];
            int newX = curX + dx[i];

            if (newY < 0 || newX < 0 || newY >= N || newX >= M) {
                continue;
            }
            // 다음 칸이 0인 경우
            if (mp[newY][newX] == 0 && dist[newY][newX][wall] == 0) {
                myQueue.push({newY, newX, wall});
                dist[newY][newX][wall] = dist[curY][curX][wall] + 1;
            }
            // 다음 칸이 벽인데도 부수고 가려는 경우
            if (mp[newY][newX] == 1) {
                // 아직 벽을 부수지 않은 상태인가? (한번이라도 부쉈다면 wall=1이 되므로 통과 못함)
                if (wall == 0) {
                    // 벽을 부순 상태로 이 칸에 온 적이 없는가?
                    if (dist[newY][newX][1] == 0) {
                        dist[newY][newX][1] = dist[curY][curX][0] + 1;
                        myQueue.push({newY, newX, 1});
                    }
                }
            }
        }
    }
}