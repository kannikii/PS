#include <iostream>

using namespace std;

int n, t;
int r, c;
char d;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};

bool InRange(int x, int y){
    return (x>=0 && x<n && y>=0 && y<n) ;
}

int main() {
    cin >> n >> t;
    cin >> r >> c >> d;
    
    // 격자 크기 4x4
    // 가장 왼쪽 위 : grid[0][0] (1행 1열)
    // 1행 2열 : grid[0][1]
    int nowx = r-1;
    int nowy = c-1;
    int dir;
    if (d == 'R') dir = 0;
    else if (d == 'D') dir = 1;
    else if (d == 'U') dir = 2;
    else dir = 3;  // L

    for (int i = 0; i < t; i++) {
        int newx = nowx + dx[dir];
        int newy = nowy + dy[dir];

        if (InRange(newx, newy)) {
            nowx = newx;
            nowy = newy;
        } else {
            dir = 3 - dir;
        }
    }

    cout<<nowx+1<<" "<<nowy+1;

    return 0;
}