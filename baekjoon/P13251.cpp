#include <iostream>
#include <vector>

using namespace std;
static long double D[2501][2501];
static vector<int> N;
int main() {
    int M;
    cin >> M;
    N.resize(M);
    int nSize = 0;
    for (int i = 0; i < M; i++) {
        cin >> N[i];  // 0번 색부터 각각의 개수 저장
        nSize += N[i];
    }

    int K;
    cin >> K;

    // 조합 DP 초기화
    for (int i = 0; i <= nSize; i++) {
        D[i][0] = 1.0;
        if (i <= K) D[i][i] = 1.0;
    }
    // 조합 DP 테이블 채우기
    for (int i = 1; i <= nSize; i++) {
        for (int j = 1; j <= min(i, K); j++) {
            D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
        }
    }
    // D[nsize][K] 에서 전부 같은 색일 확률 M번 계산하여 더하기
    // D[N[i]][K] 를 i를 M번 반복 단, N[i]>=K 인 경우에만 구해서 더함
    // 총 경우의 수 D[nSize][K] 로 나누면 확률을 구할 수 있다.
    long double sameColor = 0.0;
    for (int i = 0; i < M; i++) {
        if (N[i] >= K) sameColor += D[N[i]][K];
    }

    long double result = sameColor / D[nSize][K];
    cout.precision(15);
    cout << result << "\n";
}