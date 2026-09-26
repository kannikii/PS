#include <iostream>
#include <vector>
using namespace std;

int x1[3], y1[3];
int x2[3], y2[3];

int main() {
    vector<vector<int>> v(2001,vector<int>(2001,0));
    cin >> x1[0] >> y1[0] >> x2[0] >> y2[0];
    cin >> x1[1] >> y1[1] >> x2[1] >> y2[1];
    cin >> x1[2] >> y1[2] >> x2[2] >> y2[2];

    // 사각형 A,B를 1로 칠하고
    // 사각형 M 영역을 2로 해줘서
    // 값이 1로 남아있는 부분의 개수를 센다.

    for(int i=x1[0]+1000;i<x2[0]+1000;i++){
        for(int j=y1[0]+1000;j<y2[0]+1000;j++){
            v[i][j]=1; // 겹칠 수도 있어서 1로 둔다. 문제는 겹치지 않는다고 헷지만..
        }
    }
    for(int i=x1[1]+1000;i<x2[1]+1000;i++){
        for(int j=y1[1]+1000;j<y2[1]+1000;j++){
            v[i][j]=1; // 겹칠 수도 있어서 1로 둔다. 문제는 겹치지 않는다고 헷지만..
        }
    }
    for(int i=x1[2]+1000;i<x2[2]+1000;i++){
        for(int j=y1[2]+1000;j<y2[2]+1000;j++){
            v[i][j]=2; 
        }
    }
    
    int count=0;
    for(int i=0;i<2001;i++){
        for(int j=0;j<2001;j++){
            if(v[i][j]==1){
                count++;
            }
        }
    }

    cout<<count++;
    return 0;
}