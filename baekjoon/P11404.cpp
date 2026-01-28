#include <iostream>
#include <climits>

using namespace std;
int main() {
    int N;
    cin >> N;

    int M;
    cin >> M;
    long D[101][101];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == j)
                D[i][j] = 0;
            else
                D[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        D[a][b] = min(D[a][b], (long)c);
    }
    // O(V³) 시간 복잡도
    for (int K = 1; K <= N; K++) {          // 경유지 K에 관해
        for (int S = 1; S <= N; S++) {      // 출발 노드 S에 관해
            for (int E = 1; E <= N; E++) {  // 도착 노드 E에 관해
                if (D[S][K] != INT_MAX && D[K][E] != INT_MAX) {
                    D[S][E] = min(D[S][E], D[S][K] + D[K][E]);
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (D[i][j] == INT_MAX) {
                cout << "0 ";
            } else {
                cout << D[i][j] << " ";
            }
        }
        cout << "\n";
    }
}