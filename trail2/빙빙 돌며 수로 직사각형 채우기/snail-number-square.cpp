#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[100][100];
// 4방향 오른쪽 부터, dx[0], dx[1], dx[2], dx[3], dx[0], dx[1], ...
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0}; 

bool InRange(int x, int y){
    return (0<=x && x<n && 0<=y && y<m);
}

int main() {
    cin >> n >> m;
    // 방문 벡터 
    vector<vector<int>> answer(n,vector<int>(m,0));
    
    int nowx=0;
    int nowy=0;
    answer[nowx][nowy]=1;
    int dir=0;

    for(int i=2;i<=n*m;i++){
        // 방향 정립
        int newx=nowx+dx[dir];
        int newy=nowy+dy[dir];

        // 더이상 갈 수 없는 경우
        // 방향 90도 회전
        if(!InRange(newx, newy) || answer[newx][newy]!=0){
            dir=(dir+1)%4;
        }

        nowx=nowx+dx[dir];
        nowy=nowy+dy[dir];
        answer[nowx][nowy]=i;

    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}