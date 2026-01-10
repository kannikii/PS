#include <iostream>
#include <queue>

using namespace std;

static int input[1001][1001] = {};
static int dist[1001][1001];
static int dx[4]={1,-1,0,0};//아래,위,오른쪽,왼쪽 순서
static int dy[4]={0,0,1,-1};
static queue<pair<int,int>> myQueue;
void BFS(int row, int col);

int main() {
    int n, m;
    cin >> n >> m;
    int row = -1, col = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> input[i][j];
            dist[i][j] = -1;
            if (input[i][j] == 2) {
                row = i;
                col = j;
                
            }
        }
    }

    BFS(row, col);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(input[i][j]==0){
                cout<<0<<" ";
            }else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
}

void BFS(int row, int col) {
    myQueue.push(make_pair(row,col));
    dist[row][col] = 0;

    while(!myQueue.empty()){    //목표 : 4방향 탐색하면서 input배열 값이 1인 지역 전부 dist배열 값 채워주기 
        int curX=myQueue.front().first;
        int curY=myQueue.front().second;
        myQueue.pop();
        int newX,newY;
        for(int i=0;i<4;i++){
            newX=curX+dx[i];
            newY=curY+dy[i];
            
            if(input[newX][newY]==1&&dist[newX][newY]==-1){
                dist[newX][newY]=dist[curX][curY]+1;
                myQueue.push(make_pair(newX,newY));
            }
        }
    }
}