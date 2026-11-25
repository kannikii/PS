#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int grid[25][25];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

vector<vector<bool>> visited;
vector<int> villages;
int dfs(int x,int y){
    visited[x][y]=true;
    
    int cnt=1;

    for(int i=0;i<4;i++){
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx<0 || newx>=n || newy<0 || newy>=n){
            continue;
        }
        // 방문하지 않았고, 사람인 경우
        if(!visited[newx][newy]&&grid[newx][newy]==1){
            cnt=cnt+dfs(newx,newy);
        }
    }

    return cnt;
}

int main() {
    cin >> n;
    visited=vector<vector<bool>> (n,vector<bool>(n,false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // 마을 개수 출력
    // 마을 별 사람 수 오름 차순 출력
     // 전체 배열 탐색
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(grid[i][j]==1 && !visited[i][j]){
                villages.push_back(dfs(i,j));
            }
        }
    }

    // 오름차순 정렬
    sort(villages.begin(), villages.end());

    cout << villages.size() << '\n';

    for(int i=0;i<villages.size();i++){
        cout << villages[i] << '\n';
    }
    return 0;
}
