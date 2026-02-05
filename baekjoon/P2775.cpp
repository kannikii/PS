#include <iostream>

using namespace std;
static int D[15][15];
int main() {
    for(int i=0;i<=14;i++){
        D[i][1]=1;
        D[0][i]=i;  
    };

    for(int i=1;i<=14;i++){
        for(int j=2;j<=14;j++){
             D[i][j]=D[i][j-1]+D[i-1][j];
        }
       
    }
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>K>>N;
        cout<<D[K][N]<<"\n";
    }
    // // 0층 초기화
    // for (int i = 1; i <= 14; i++) {
    //     D[0][i] = i;
    // }

    // // DP 테이블 채우기
    // for (int k = 1; k <= 14; k++) {
    //     for (int n = 1; n <= 14; n++) {
    //         D[k][n] = 0;
    //         for (int i = 1; i <= n; i++) {
    //             D[k][n] += D[k - 1][i];
    //         }
    //     }
    // }

    // int T;
    // cin >> T;
    // while (T--) {
    //     int k, n;
    //     cin >> k >> n;
    //     cout << D[k][n] << '\n';
    // }

}