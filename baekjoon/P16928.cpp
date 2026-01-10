#include <iostream>
#include <queue>
#include <vector>

using namespace std;
static int N, M;
static vector<int> ladder;
static vector<int> snake;
static vector<bool> visited;
static queue<pair<int,int>> myQueue;
void BFS(int start);
static int result = 0;

int main() {
    cin >> N >> M;
    ladder = vector<int>(101, 0);
    snake = vector<int>(101, 0);
    visited = vector<bool>(101, false);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ladder[x] = y;
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        snake[u] = v;
    }

    BFS(1);
    cout << result << "\n";
}
void BFS(int start) {
    visited[start] = true;
    myQueue.push(make_pair(start,0));

    while (!myQueue.empty()) {
        //  1번부터 시작해서 count=0 주사위 굴릴때마다 count+1 ,
        //  주사위 굴려 나온수 + 원래 숫자로 다시 탐색->
        //  반복마다 ladder[],snake[] 배열 값 존재하는지 검사->
        //  있다면 배열위치로 이동 후 재탐사 반복

        int current = myQueue.front().first;
        int trial=myQueue.front().second;
        myQueue.pop();

        int newNode;
        if (current == 100) {
            result=trial;
            break;
        }

        for (int i = 1; i <= 6; i++) {
            newNode = current + i;
            if (newNode > 100) continue;

            if (ladder[newNode] != 0) {
                newNode = ladder[newNode];
            }
            if (snake[newNode] != 0) {
                newNode = snake[newNode];
            }
            if (!visited[newNode]) {
                visited[newNode] = true;
                myQueue.push(make_pair(newNode,trial+1));
            }
        }
        //result++;
    }
}
