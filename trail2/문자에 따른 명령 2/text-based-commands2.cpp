#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string dirs;
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};
int main() {
    cin >> dirs;
    int dir=1;
    int nowx=0;
    int nowy=0;
    for(int i=0;i<dirs.length();i++){
        if(dirs[i]=='F'){
            nowx+=dx[dir];
            nowy+=dy[dir];
        }else{
            if(dirs[i]=='L'){
                dir=(dir+1)%4;
            }else if(dirs[i]=='R'){
                if(dir-1<0){
                    dir=4-(abs(dir-1)%4);
                }else{
                    dir=dir-1;
                }
            }
        }
    }
    cout<<nowx<<" "<<nowy;
    return 0;
}