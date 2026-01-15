#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
static vector<int> answer;
// 이동 케이스 6가지
// A->B, A->C, B->A, B->C, C->A, C->B 6개의 케이스로 이동
// 물통에 번호를 붙임 A:0, B:1, C:2
static int Sender[6] = {0, 0, 1, 1, 2, 2};
static int Receiver[6] = {1, 2, 0, 2, 0, 1};
// A,B 물통에 들은 물의 양이 탐색에 활용되는 좌표값 (C 물통의 물의 양은 A+B로 고정)
static bool visited[201][201];  // index가 각각 A,B 물통의 물의 양 (visited[0][0]=true 는 즉, A,B,C가 0,0,10인 경우는 이미 탐색)
static int limit[3];  // 각 물통의 최대 용량
static int total;     // 전체 물의 양 (C 초기값)

void BFS();
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;
    limit[0] = A;
    limit[1] = B;
    limit[2] = C;
    total = C;
    BFS();
    sort(answer.begin(), answer.end());
    for (int x : answer) {
        cout << x << " ";
    }
    cout << "\n";
}

void BFS() {
    queue<pair<int, int>> myQueue;
    myQueue.push({0, 0});
    visited[0][0] = true;
    // answer배열에 이때의 C값 우선 저장
    answer.push_back(total);

    while (!myQueue.empty()) {
        int curA = myQueue.front().first;
        int curB = myQueue.front().second;
        int curC = total - (curA + curB);
        myQueue.pop();
        // 현재 상태를 now 배열에 저장
        int now[3] = {curA, curB, curC};

        // 물통의 6가지 이동 경우 (이 부분이 이 문제의 핵심 역으로 그래프 그리면서 탐색)
        for (int i = 0; i < 6; i++) {
            int next[3] = {now[0], now[1], now[2]};

            int from = Sender[i];
            int to = Receiver[i];

            // 부을 수 있는 물의 양 min(보내는 물통에 있는 물의 양, 받는 물통의 남은 공간) 둘 중 더 적은 양만 이동할 수 있는 물의 양이다. 
            // 3L를 보낼 수 있지만, 받는 쪽이 2L만 받을 수 있다면 이동하는 물의 양은 2L 뿐이므로 min() 함수를 사용한다.
            int move = min(next[from], limit[to] - next[to]);

            next[from] -= move;
            next[to] += move;

            int newA = next[0];
            int newB = next[1];
            int newC = next[2];

            // A,B의 물의 양을 통하여 방문 배열 체크
            if (!visited[newA][newB]) {
                visited[newA][newB] = true;
                myQueue.push({newA, newB});

                // A의 물의 양이 0일 때 C의 물의 양을 정답 변수에 저장
                if (newA == 0) {
                    answer.push_back(newC);
                }
            }
        }
    }
}