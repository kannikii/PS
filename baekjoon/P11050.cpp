#include <iostream>
using namespace std;
static int D[11][11];
int main() {
    int N, K;
    cin >> N >> K;

    // DP 테이블 초기화
    for (int i = 0; i <= N; i++) {
        D[i][1] = i;  // i개 중 1개를 선택하는 경우의 수는 i개
        D[i][0] = 1;  // i개 중 1개도 선택하지 않는 경우의 수는 1개
        D[i][i] = 1;  // i개 중 i개를 선택하는 경우의 수는 1개
    }
    // 조합 점화식 활용해서 DP 테이블 채우기
    // D[i][j]= D[i-1][j]+D[i-1][j-1]
    // 1≤j≤i−1 범위 중요 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
        }
    }
    cout << D[N][K] << "\n";
}