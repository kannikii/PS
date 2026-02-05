#include <iostream>
#include <vector>
using namespace std;
static long long D[202][202];  // N+M개에서 N or M개를 뽑는 조합
const long long LIM = 1000000000LL;
int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;
    // 조합 문제인 이유
    // N+M길이의 자리에서 z를 놓을수 있는 자리(M개)를 선택하는 문제이므로
    // ᴺ⁺ᴹCᴹ z자리를 선택하면 나머지 자리는 당연히 a가 되기때문 

    // 조합 DP 테이블 생성
    for (int i = 0; i <= N + M; i++) {
        D[i][1] = i;
        D[i][i] = 1;
        D[i][0] = 1;
    }
    for (int i = 1; i <= N + M; i++) {
        for (int j = 1; j < i; j++) {
            D[i][j] = min(LIM, D[i - 1][j] + D[i - 1][j - 1]);
        }   // K의 최댓값 보다 큰 조합결과는 필요없고, 계산하다가 오버플로우 발생하므로
    }

    // ᵢCⱼ = D[i][j] 완성
    if (D[N + M][M] < K) cout << "-1";
    // K번째 문자열
    // 현재 자릿수에서 a를 선택했을 때
    // 남은 문자로 만들 수 있는 경우의 수 T
    // a 하나 선택하면 D[N-1+M][M]
    else {
        while (N > 0 || M > 0) {
            if (N == 0) {
                cout << "z";
                M--;
            } else if (M == 0) {
                cout << "a";
                N--;
            } else {
                long long cnt = D[N - 1 + M][M];
                if (cnt >= K) {
                    cout << "a";
                    N--;
                } else {
                    cout << "z";
                    K -= cnt;
                    M--;
                }
            }
        }
    }
}
