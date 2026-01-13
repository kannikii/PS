#include <iostream>
#include <queue>
#include <string>

using namespace std;
static int N, M;
static char A[601][601];
static int cnt = 0;
static int dx[4] = {1, -1, 0, 0};
static int dy[4] = {0, 0, 1, -1};
static queue<pair<int, int>> myQueue;
void BFS(int y, int x);
int main() {
    cin >> N >> M;  // N:세로, M:가로
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            A[i][j] = line[j];
        }
    }
    int row = 0;
    int col = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == 'I') {
                col = i;
                row = j;
            }
        }
    }
    BFS(col, row);

    if (cnt == 0) {
        cout << "TT" << "\n";
    } else {
        cout << cnt << "\n";
    }
}

void BFS(int y, int x) {
    myQueue.push(make_pair(y, x));

    while (!myQueue.empty()) {
        int curY = myQueue.front().first;
        int curX = myQueue.front().second;
        myQueue.pop();
        for (int i = 0; i < 4; i++) {
            int newY = curY + dy[i];
            int newX = curX + dx[i];
            if (newX < 0 || newX >= M || newY < 0 || newY >= N) continue;
            if(A[newY][newX]=='O'){
                myQueue.push(make_pair(newY,newX));
                A[newY][newX]='I';
            }else if(A[newY][newX]=='P'){
                cnt++;
                myQueue.push(make_pair(newY,newX));
                A[newY][newX]='I';
            } else if(A[newY][newX]=='X'){
                continue;
            }
        }
    }
}