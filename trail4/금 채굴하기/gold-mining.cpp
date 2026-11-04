#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n, m;
int grid[20][20];

// (i, j)를 중심으로 K번 이내로 갈 수 있는 칸의 금 개수
int findgold(int k, int i, int j){
    int goldcount = 0;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            if(abs(x - i) + abs(y - j) <= k){   // 마름모 안인가
                goldcount += grid[x][y];
            }
        }
    }
    return goldcount;
}

int main() {
    cin >> n >> m;
    int gold = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1){
                gold++;
            }
        }
    }

    // 비용 계산 해서 대략적인 k값 제한
    // 전체 금을 다 캐도 est원이므로, cost(k) <= est인 k까지만 의미가 있다
    int est = gold * m;
    int possibleK = 0;
    while((possibleK + 1) * (possibleK + 1) + (possibleK + 2) * (possibleK + 2) <= est){
        possibleK++;                            // cost(possibleK+1)이 est 이하이면 한 칸 확장
    }
    possibleK = min(possibleK, 2 * (n - 1));    // 격자 전체를 덮는 k를 넘을 필요 없음

    int answer = 0;                             // 금이 없으면 0
    for(int k = 0; k <= possibleK; k++){        // k=0부터 일반 루프로 처리
        int cost = k * k + (k + 1) * (k + 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int g = findgold(k, i, j);
                if(g * m >= cost){              // 손해를 보지 않는 경우만
                    answer = max(answer, g);
                }
            }
        }
    }

    cout << answer;
    return 0;
}