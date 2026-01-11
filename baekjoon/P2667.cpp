#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
static int N;
static int house = 1;
static int houses[26][26] = {};
static int dx[4] = {1, -1, 0, 0};
static int dy[4] = {0, 0, 1, -1};
static queue<pair<int, int>> myQueue;
void BFS(int y, int x);

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;  
        for (int j = 0; j < N; j++) {
            houses[i][j] = line[j] - '0';
        }
    }
    vector<int> result;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (houses[i][j] == 1) {
                house = 0;
                BFS(i, j);
                // 가구수 출력
                result.push_back(house);
            }
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for (int i : result) {
        cout << i << "\n";
    }
}

void BFS(int y, int x) {
    myQueue.push(make_pair(y, x));
    houses[y][x] = 0;
    while (!myQueue.empty()) {
        int curY = myQueue.front().first;
        int curX = myQueue.front().second;
        myQueue.pop();
        house++;

        for (int i = 0; i < 4; i++) {
            int newY = curY + dy[i];
            int newX = curX + dx[i];
            if (newY < 0 || newY >= N || newX < 0 || newX >= N) continue;
            if (houses[newY][newX] != 0) {
                myQueue.push(make_pair(newY, newX));
                houses[newY][newX] = 0;
            }
        }
    }
}