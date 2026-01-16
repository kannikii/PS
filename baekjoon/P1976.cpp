#include <iostream>

// 인접 행렬

using namespace std;
static int parent[201];
void unionfunc(int a, int b);
int find(int a);
int main() {
    int N, M;
    cin >> N;
    cin >> M;
    int adj_matrix[201][201];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> adj_matrix[i][j];
        }
    }
    int route[1001];
    for (int j = 1; j <= M; j++) {
        cin >> route[j];
    }

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    // 인접 행렬 탐색하며 연결하며 union 연산
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (adj_matrix[i][j] == 1) {
                unionfunc(i, j);
            }
        }
    }
    int temp = find(route[1]);
    for (int j = 2; j <= M; j++) {
        // route[]에 속한 도시들이 모두 같은 대표노드를 갖는지 확인 (find())
        if (temp != find(route[j])) {
            cout<<"NO"<<"\n";
            return 0;
        } 
    }
    cout<<"YES"<<"\n";
    return 0;
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