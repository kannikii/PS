#include <iostream>
#include <vector>

using namespace std;

int n;
char dir[100];
int dist[100];
vector<int> dx={1,0,-1,0};
vector<int> dy={0,-1,0,1};
int main() {
    cin >> n;
    int nowx=0;
    int nowy=0;
    for (int i = 0; i < n; i++) {
        cin >> dir[i] >> dist[i];
        if(dir[i]=='N'){
            for(int j=0;j<dist[i];j++){
                nowx+=dx[3];
                nowy+=dy[3];
            }
        }else if(dir[i]=='W'){
            for(int j=0;j<dist[i];j++){
                nowx+=dx[2];
                nowy+=dy[2];
            }
        }else if(dir[i]=='S'){
            for(int j=0;j<dist[i];j++){
                nowx+=dx[1];
                nowy+=dy[1];
            }
        }else if(dir[i]=='E'){
            for(int j=0;j<dist[i];j++){
                nowx+=dx[0];
                nowy+=dy[0];
            }
        }
    }

    cout<<nowx<<" "<<nowy;

    return 0;
}