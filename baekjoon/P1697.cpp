#include <iostream>
#include <queue>

using namespace std;

static int N, K;
static int answer = 0;
static bool visited[100001] = {false};
static queue<pair<int, int>> myQueue;

void BFS(int start);

int main() {
    cin >> N >> K;

    BFS(N);
    cout << answer << "\n";
}

void BFS(int start) {
    myQueue.push({start, 0});  // (위치, 시간)
    visited[start] = true;

    while (!myQueue.empty()) {
        int now = myQueue.front().first;
        int curTime = myQueue.front().second;
        myQueue.pop();

        if (now == K) {
            answer = curTime;
            return;
        }

        int nx1 = now - 1;
        int nx2 = now + 1;
        int nx3 = now * 2;

        if (nx1 >= 0 && nx1 <= 100000 && !visited[nx1]) {
            visited[nx1] = true;
            myQueue.push({nx1, curTime + 1});
        }
        if (nx2 >= 0 && nx2 <= 100000 && !visited[nx2]) {
            visited[nx2] = true;
            myQueue.push({nx2, curTime + 1});
        }
        if (nx3 >= 0 && nx3 <= 100000 && !visited[nx3]) {
            visited[nx3] = true;
            myQueue.push({nx3, curTime + 1});
        }
    }
}
