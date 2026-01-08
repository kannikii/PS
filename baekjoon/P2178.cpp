#include <iostream>
#include <queue>
#include <vector>

using namespace std;
static int dx[] = {0, 1, 0, -1};
static int dy[] = {1, 0, -1, 0};
static int A[101][101];
static bool visited[101][101]={false};
static int N, M;
void BFS(int x, int y);
int main() {
    cin >> N >> M;
    //(N,M)이 종료지점
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            A[i][j] = s[j] - '0';
        }
    }
    BFS(0, 0);
    cout<<A[N-1][M-1]<<"\n";
}

void BFS(int x, int y) {
    queue<pair<int, int>> myqueue;
    myqueue.push(make_pair(x, y));

    while (!myqueue.empty()) {
        int now[2];
        now[0] = myqueue.front().first;
        now[1] = myqueue.front().second;
        myqueue.pop();
        visited[x][y] = true;
        // 4방향 벡터 탐색
        for (int k = 0; k < 4; k++) {
            int nx = now[0] + dx[k];
            int ny = now[1] + dy[k];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {  // 좌표 유효성 검사
                if (A[nx][ny] != 0 && !visited[nx][ny]) {  // 미방문 노드 검사
                    visited[nx][ny] = true;
                    A[nx][ny] = A[now[0]][now[1]]+1;  // 깊이 업데이트
                    myqueue.push(make_pair(nx, ny));
                }
            }
        }
    }
}