#include <iostream>
using namespace std;
static int a[1025][1025] = {};
static int S[1025][1025] = {};
void prefixSumDP(int x1, int y1, int x2, int y2);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + a[i][j];
        }
    }
    for (int i = 1; i <= M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 합 배열에서 값 뽑아내기
        prefixSumDP(x1, y1, x2, y2);
    }
}
void prefixSumDP(int x1, int y1, int x2, int y2) {
    cout << S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1]
         << "\n";
}