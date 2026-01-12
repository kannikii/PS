#include <iostream>
#include <queue>
#include <vector>

using namespace std;
static int A[1001][1001] = {};
static int M, N;
static int dx[4] = {1, -1, 0, 0};
static int dy[4] = {0, 0, 1, -1};
static queue<pair<int, int>> myQueue;
void BFS(queue<pair<int, int>>& myQueue);
int main() {
    
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == 1) {
                myQueue.push({i, j});
            }
        }
    }
    BFS(myQueue);
    // 처음부터 다 익어 있으면 1출력, 절대 못 익는게 있으면 -1 출력
    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == 0) {
                cout << -1 << "\n";
                return 0;
            }
            answer = max(answer, A[i][j]);
        }
    }

    cout << answer - 1 << "\n";
}

void BFS(queue<pair<int, int>>& myQueue) {
    while (!myQueue.empty()) {
        int curY = myQueue.front().first;
        int curX = myQueue.front().second;
        myQueue.pop();
        
        for (int i = 0; i < 4; i++) {
            int newY = curY + dy[i];
            int newX = curX + dx[i];
            if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
            if (A[newY][newX] == 0) {
                myQueue.push(make_pair(newY, newX));
                A[newY][newX] = A[curY][curX] + 1;
            }
        }
    }
}