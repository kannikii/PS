#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int grid[200][200];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int maxV=0;
    // 가로나 세로로 2칸 짜리 한줄 + 양 옆 중 가장 큰 수 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j+1<m){
                int tmp=grid[i][j]+grid[i][j+1];
                int maxtmp=0;
                for(int k=j;k<j+2;k++){
                    if(i-1<0){
                        maxtmp=max(maxtmp,grid[i+1][k]);
                    }else if(i+1>=m){
                        maxtmp=max(maxtmp,grid[i-1][k]);
                    }else {
                        maxtmp=max(maxtmp,grid[i-1][k]);
                        maxtmp=max(maxtmp,grid[i+1][k]);
                    }
                }
                // 최댓값 검사
                maxV=max(maxV,maxtmp+tmp);
            }
        }
    }

    // 세로 
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if(i+1<n){
                int tmp=grid[i][j]+grid[i+1][j];
                int maxtmp=0;
                for(int k=i;k<i+2;k++){
                    if(j-1<0){
                        maxtmp=max(maxtmp,grid[k][j+1]);
                    }else if(j+1>=n){
                        maxtmp=max(maxtmp,grid[k][j-1]);
                    }else {
                        maxtmp=max(maxtmp,grid[k][j+1]);
                        maxtmp=max(maxtmp,grid[k][j-1]);
                    }
                }
                maxV=max(maxV,maxtmp+tmp);
            }
        }
    }

    // 가로 3개 한줄 검사
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j+2<m){
                maxV=max(maxV,grid[i][j]+grid[i][j+1]+grid[i][j+2]);
            }
        }
    }

    // 세로 3개 한줄 검사
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if(i+2<n){
                maxV=max(maxV,grid[i][j]+grid[i+1][j]+grid[i+2][j]);
            }
        }
    }

    cout<<maxV;
    return 0;
}
