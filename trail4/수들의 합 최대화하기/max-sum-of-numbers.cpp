#include <iostream>
#include <vector>

using namespace std;

int n;
int grid[10][10];
vector<bool> visited;
int answer=0;
int sum=0;
vector<int> v;
void choose(int cur){
    
    if(cur==n){
        answer=max(answer,sum);
        return;
    }
    
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            v.push_back(grid[cur][i]);
            visited[i]=true;
            sum+=grid[cur][i];
            choose(cur+1);
            v.pop_back();
            visited[i]=false;
            sum-=grid[cur][i];
        }
    }
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // 각 행과 열에 정확히 1개의 색칠된 칸
    visited=vector<bool> (n,false); // 0~n 개 중 하나 선택하면 다음 n-1개 행에서 그 열 선택 못함

    choose(0);

    cout<<answer;
    return 0;
}
