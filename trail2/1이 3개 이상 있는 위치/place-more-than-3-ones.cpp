#include <iostream>

using namespace std;

int n;
int grid[100][100];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool InRange (int x , int y){
    return (0<=x && x<n && 0<=y && y<n);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int nowx=0;
    int nowy=0;
    int answer=0; // 인접한 1이 3개 이상인 좌표의 수 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            nowx=i;
            nowy=j;
            int cnt=0;
            for(int k=0;k<4;k++){   // 4방향 검사
                int nx=nowx+dx[k];
                int ny=nowy+dy[k];
                if(InRange(nx,ny) && grid[nx][ny]==1){
                    cnt++;
                }
            }
            if(cnt>=3){
                answer++;
            }
        }
    }
    
    cout<<answer;
    return 0;
}