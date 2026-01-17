// 최소 시간 계산 순서를 위상 정렬 순서로 고정하여 쉽게 계산하기 위해 위상 정렬사용
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
static int N;
static vector<int> D;
static vector<int> structTime;
static vector<vector<int>> adj_list;
int main() {
    cin >> N;
    structTime = vector<int>(N + 1, 0);
    D = vector<int>(N + 1, 0);
    adj_list.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> structTime[i];
        while (true) {
            int preTemp;
            cin >> preTemp;
            if (preTemp == -1) {
                break;
            } else {  // 뒤에 오는 입력이 필요한 선행 건물이므로 이 입력에 i 번째 노드를 달아준다.
                adj_list[preTemp].push_back(i);
            }
        }
    }

    // 진입 차수 배열 초기화
    for (int i = 1; i <= N; i++) {
        for (int j : adj_list[i]) {
            D[j]++;
        }
    }

    queue<int> myQueue;
    vector<int> result(N + 1, 0);  // result[i] = i번 건물이 완성되는 최소 시간
    for (int i = 1; i <= N; i++) {
        if (D[i] == 0) {
            myQueue.push(i);
            result[i] = structTime[i];
        }
    }

    while (!myQueue.empty()) {
        int now = myQueue.front();
        myQueue.pop();
        // result[now]=max(result[prev1],result[prev2])+structTime[now]
        for (int next : adj_list[now]) {
            // now를 거쳐서 next를 짓는 경우 시간 갱신
            result[next] = max(result[next], result[now] + structTime[next]);
            D[next]--;
            if (D[next] == 0) {
                myQueue.push(next);
            }
        }
    }
 
    for (int i = 1; i <= N; i++) {
        cout << result[i] << "\n";
    }
}