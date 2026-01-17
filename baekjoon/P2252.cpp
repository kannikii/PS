#include <iostream>
#include <queue>
#include <vector>

using namespace std;
static vector<vector<int>> adj_list;
static vector<int> D;
int main() {
    int N, M;
    cin >> N >> M;
    adj_list.resize(N + 1);
    D = vector<int>(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj_list[A].push_back(B);
    }

    // 진입 차수 배열 D 초기화
    for (int i = 1; i <= N; i++) {
        for (int j : adj_list[i]) {
            D[j]++;
        }
    }
    // 위상 정렬 수행
    queue<int> myQueue;
    for (int i = 1; i <= N; i++) {
        if (D[i] == 0) {
            myQueue.push(i);
        }
    }

    while (!myQueue.empty()) {
        int now = myQueue.front();
        myQueue.pop();
        cout<<now<<" ";
        for (int i : adj_list[now]) {
            D[i]--;
            if(D[i]==0){
                myQueue.push(i);
            }
        }
    }
}