#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef struct Edge {
    int s, e, v;
    bool operator>(const Edge& temp) const { return v > temp.v; }
} Edge;
static vector<int> parent;
static priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
void unionfunc(int a, int b);
int find(int a);
int main() {
    int N;
    cin >> N;
    parent.resize(N + 1);
    char A[51][51];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }
    // 입력을 숫자로 변경
    int B[51][51];  // 인접 행렬
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (A[i][j] >= 97) {
                B[i][j] = A[i][j] - 96;
            } else if (A[i][j] == '0') {
                B[i][j] = 0;
            } else {
                B[i][j] = A[i][j] - 38;
            }
        }
    }
    // i==j인 경우는 무시
    int total = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (B[i][j] > 0) {
                total += B[i][j];
            }
        }
    }

    // MST 연결 시작
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j && B[i][j] > 0) {
                pq.push({i, j, B[i][j]});
            }
        }
    }
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    int useEdge = 0;   // N-1 되면 종료
    int MSTcount = 0;  // 사용한 랜선 길이의 합
    while (!pq.empty() && useEdge < N - 1) {
        Edge now = pq.top();
        pq.pop();
        // 같은 부모가 아니라면 -> 연결해도 사이클이 생기지 않는 다면
        if (find(now.s) != find(now.e)) {
            unionfunc(now.s, now.e);
            MSTcount += now.v;
            useEdge++;
        }
    }
    if (useEdge != N - 1) {
        cout << -1 << "\n";
        return 0;
    }
    // total- MST합 출력
    cout << total - MSTcount << "\n";
}

void unionfunc(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}
int find(int a) {
    if (a == parent[a]) {
        return a;
    } else {
        return parent[a] = find(parent[a]);
    }
}