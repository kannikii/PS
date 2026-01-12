#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
static int A[101][101][101] = {};  // H N M 높이,세로,가로 순
static int H, N, M;
static int dx[6] = {1, -1, 0, 0, 0, 0};
static int dy[6] = {0, 0, 1, -1, 0, 0};
static int dz[6] = {0, 0, 0, 0, 1, -1};
static queue<tuple<int, int, int>> myQueue;
void BFS(queue<tuple<int, int, int>>& myQueue);

int main() {
    // M:가로, N:세로, H:높이
    cin >> M >> N >> H;
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[k][i][j];
            }
        }
    }

    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (A[k][i][j] == 1) {
                    myQueue.push({k, i, j});
                }
            }
        }
    }
    BFS(myQueue);
    int answer = 0;

    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (A[k][i][j] == 0) {
                    cout << -1 << "\n";
                    return 0;
                }
                answer = max(answer, A[k][i][j]);
            }
        }
    }

    cout << answer - 1 << "\n";
}
void BFS(queue<tuple<int, int, int>>& myQueue) {
    while (!myQueue.empty()) {
        auto cur = myQueue.front();
        int curZ = get<0>(cur);
        int curY = get<1>(cur);
        int curX = get<2>(cur);
        myQueue.pop();

        for (int i = 0; i < 6; i++) {
            int newZ = curZ + dz[i];
            int newY = curY + dy[i];
            int newX = curX + dx[i];
            if (newZ < 0 || newZ >= H || newY < 0 || newY >= N || newX < 0 ||
                newX >= M)
                continue;
            if (A[newZ][newY][newX] == 0) {
                myQueue.push({newZ, newY, newX});
                A[newZ][newY][newX] = A[curZ][curY][curX] + 1;
            }
        }
    }
}