#include <iostream>
#include <vector>

using namespace std;

int n, m;
int grid[100][100];

vector<vector<bool>> visited;
int dx[2]={0,1};
int dy[2]={1,0};
bool found=false;
void dfs(int cur_x, int cur_y){
    if(cur_x==n-1 && cur_y==m-1){
        found=true;
        return;
    }


    for(int i=0;i<2;i++){
        int new_x=cur_x+dx[i];
        int new_y=cur_y+dy[i];
        if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m){
                if(grid[new_x][new_y]==1 && !visited[new_x][new_y]){
                visited[new_x][new_y]=true;
                dfs(new_x,new_y);
            }
        }
        
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }


    visited=vector<vector<bool>> (n,vector<bool>(m,false));
    
    visited[0][0]=true;
    dfs(0,0);
    if(!found){
        cout<<0;
    }else{
        cout<<1;
    }

    return 0;
}
