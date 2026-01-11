#include <iostream>
#include <queue>

using namespace std;
static int M, N, K;
static int cb_field[51][51] = {};
static int dx[4] = {1, -1, 0, 0};
static int dy[4] = {0, 0, 1, -1};
static queue<pair<int, int>> myQueue;
void BFS(int y, int x);
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        
        cin >> M >> N >> K;

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                cb_field[y][x] = 0;
            }
        }

        for (int j = 0; j < K; j++) {
            int x, y;
            cin >> x >> y;
            cb_field[y][x] = 1;
        }

        int worms = 0;

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (cb_field[y][x] == 1) {
                    BFS(y, x);
                    worms++;
                }
            }
        }
        cout << worms << "\n";
    }
}
void BFS(int y, int x) {
    myQueue.push(make_pair(y, x));
    cb_field[y][x] = 0;
    while (!myQueue.empty()) {
        int curY = myQueue.front().first;
        int curX = myQueue.front().second;
        myQueue.pop();
        for (int i = 0; i < 4; i++) {
            int newY = curY + dy[i];
            int newX = curX + dx[i];
            if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
            if (cb_field[newY][newX] != 0) {
                myQueue.push(make_pair(newY, newX));
                cb_field[newY][newX] = 0;
            }
        }
    }
}