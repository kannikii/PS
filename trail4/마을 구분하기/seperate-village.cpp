#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int grid[25][25];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
vector<vector<bool>> visited;
vector<int> villages;
int dfs(int x , int y){
    visited[x][y]=true;
    int cnt=1;
    for(int i=0;i<4;i++){
        int newx=x+dx[i];
        int newy=y+dy[i];

        if(newx<0 || newx >=n || newy<0 || newy>=n ){
            continue;
        }
        if(!visited[newx][newy] && grid[newx][newy]==1){
            cnt+=dfs(newx,newy);
        }
    }
    return cnt;
}

int main() {
    cin >> n;
    visited=vector<vector<bool>> (n,(vector<bool>(n,false)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && !visited[i][j]){
                villages.push_back(dfs(i,j));
            }
        }
    }

    cout<<villages.size()<<"\n";

    sort(villages.begin(),villages.end());
    for(auto it:villages){
        cout<<it<<"\n";
    }

    return 0;
}
