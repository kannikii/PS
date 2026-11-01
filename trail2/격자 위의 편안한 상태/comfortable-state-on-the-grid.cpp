#include <iostream>
#include <vector>
using namespace std;

int N, M;
int r[10000], c[10000];
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};

vector<vector<int>> board;

int isStable(int x, int y){
    int cnt=0;
    for(int i=0;i<4;i++){
        int newX;
        int newY;
        newX=x+dx[i];
        newY=y+dy[i];
        if(newX>=0 && newX<N && newY>=0 && newY<N && board[newX][newY]!=0){
            cnt++;
        }
    }
    return cnt;
}
int main() {
    cin >> N >> M;
    board=vector<vector<int>>(N, vector<int>(N, 0));

    for (int i = 0; i < M; i++) {
        cin >> r[i] >> c[i];
        int nowX=r[i]-1;
        int nowY=c[i]-1;
        board[nowX][nowY]++;
        
        if(isStable(nowX,nowY)==3){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    
    
    return 0;
}