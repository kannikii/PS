#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> W(N + 1), V(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }

    vector<int> D(K + 1, 0);

    for (int i = 1; i <= N; i++) {
        for (int w = K; w >= 0; w--) {
            // Case 1: 이 물건을 못 넣는 경우
            if (w < W[i]) {
                // 아무것도 하지 않음 → D[w] 그대로 유지
                continue;
            }

            // Case 2: 이 물건을 넣을 수 있는 경우
            int 넣지_않은_경우 = D[w];
            int 넣은_경우 = D[w - W[i]] + V[i];

            if (넣은_경우 > 넣지_않은_경우) {
                D[w] = 넣은_경우;
            }
        }
    }

    cout << D[K] << "\n";
}
