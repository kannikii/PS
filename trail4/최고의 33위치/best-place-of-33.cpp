#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int grid[20][20];
int countCoin(int x,int y){
    int cnt=0;
    for(int i=x;i<x+3;i++){
        for(int j=y;j<y+3;j++){
            if(grid[i][j]==1){
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // N-1 까지 가능 (출발점x +2 <=N-1 && 출발점y +2 <=N-1)-> 3x3 탐색 가능
    // 출발점 갱신 for(for(())

    // 00 01 02
    // 10 11 12
    // 20 21 22

    // 01 02 03
    // 11 12 13
    // 21 22 23

    int maxCoin=0;
    // 출발점 갱신
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i+2<N && j+2<N){
                int cnt=countCoin(i,j);
                maxCoin=max(maxCoin,cnt);
            }
        }
    }
    cout<<maxCoin;
    return 0;
}
