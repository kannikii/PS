#include <iostream>
#include <queue>
#include <vector>
using namespace std;
static int I;
static int sx, sy;
static int ex, ey;
static int cnt = 0;
static int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
static int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
static queue<pair<int, int>> myQueue;
static bool visited[300][300];
static int dist[300][300];
void BFS(int sy, int sx);
int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> I;

        cin >> sx >> sy;
        cin >> ex >> ey;

        for (int i = 0; i < I; i++) {
            for (int j = 0; j < I; j++) {
                visited[i][j] = false;
                dist[i][j] = 0;
            }
        }
        while (!myQueue.empty()) myQueue.pop();
        if (sx == ex && sy == ey) {
            cout << 0 << "\n";
            continue;
        }

        BFS(sy, sx);
        cout << dist[ey][ex] << "\n";
    };
}

void BFS(int sy, int sx) {
    myQueue.push({sy, sx});
    visited[sy][sx] = true;
    dist[sy][sx] = 0;

    while (!myQueue.empty()) {
        int curY = myQueue.front().first;
        int curX = myQueue.front().second;
        int curDist = dist[curY][curX];
        myQueue.pop();

        for (int i = 0; i < 8; i++) {
            int newY = curY + dy[i];
            int newX = curX + dx[i];
            if (newY < 0 || newX < 0 || newY >= I || newX >= I) continue;
            if (!visited[newY][newX]) {
                visited[newY][newX] = true;
                dist[newY][newX] = curDist + 1;

                if (newY == ey && newX == ex) return;
                
                myQueue.push({newY, newX});
            }
        }
    }
}