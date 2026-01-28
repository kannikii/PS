#include <iostream>

using namespace std;

int main() {
    // 플로이드-워셜 점화식
    // D[S][E]=min(D[S][E],D[S][K]+D[K][E])
    int N, M;
    cin >> N >> M;
    int D[N + 1][N + 1];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == j)
                D[i][j] = 0;
            else
                D[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < M; i++) {
        int S, E, W;
        cin >> S >> E >> W;
        D[S][E]=W;
    }
    // O(V³) 시간 복잡도 
    for(int K=1;K<=N;K++){  // 경유지 K에 관해
        for(int S=1;S<=N;S++){  // 출발 노드 S에 관해
            for(int E=1;E<=N;E++){  // 도착 노드 E에 관해
                D[S][E]=min(D[S][E],D[S][K]+D[K][E]);
            }
        }
    }
};