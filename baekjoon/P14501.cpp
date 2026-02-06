#include <iostream>
using namespace std;
static int T[16];
static int P[16];
static int D[16];  // D[i]=i일 부터 퇴사일 까지 벌 수 있는 최대 수입
int main() {
    int N;
    cin >> N;
    // 1일 부터 N일까지의 상담 일정표 입력
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }
    D[0] = 0;
    for (int i = 1; i <= N; i++) {
        // i 번째 날에 할 수 있는 선택 2가지
        // 1. i일 상담을 안 한다. -> 전날 까지의 최적값
        D[i + 1] = max(D[i + 1], D[i]);

        // 2. i일 상담을 한다. -> 상담 기간 T[i], 끝나는 날 : i+T[i]-1 이 N을 넘으면
        if(i + T[i] - 1 <= N){
            D[i + T[i]] = max(D[i + T[i]], D[i] + P[i]);
        }
    }
    cout<<D[N+1]<<"\n";
}