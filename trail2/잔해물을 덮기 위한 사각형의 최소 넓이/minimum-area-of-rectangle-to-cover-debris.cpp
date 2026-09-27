#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int x1[2], y1[2];
int x2[2], y2[2];

int main() {
    vector<vector<int>> v(2001,vector<int>(2001,0));

    cin >> x1[0] >> y1[0] >> x2[0] >> y2[0];
    cin >> x1[1] >> y1[1] >> x2[1] >> y2[1];
    for(int i=x1[0]+1000;i<x2[0]+1000;i++){
        for(int j=y1[0]+1000;j<y2[0]+1000;j++){
            v[i][j]=1;
        }
    }

    for(int i=x1[1]+1000;i<x2[1]+1000;i++){
        for(int j=y1[1]+1000;j<y2[1]+1000;j++){
            v[i][j]=0;
        }
    }

    // 남아있는 1 중 가장 좌측 하단 위치와 가장 우측 상단 위치 구함
    int minI = 2001;
    int maxI = 0;
    int minJ = 2001;
    int maxJ = 0;
    bool exist = false;
    for(int i = 0; i < 2001; i++){
        for(int j = 0; j < 2001; j++){
            if(v[i][j] == 1){
                exist = true;
                minI = min(minI, i);
                maxI = max(maxI, i);
                minJ = min(minJ, j);
                maxJ = max(maxJ, j);
            }
        }
    }
    if (!exist) {
        cout << 0;
    }
    else {
        cout << (maxI - minI + 1) * (maxJ - minJ + 1);
    }
    
    return 0;
}