#include <iostream>
#include <string>

using namespace std;

string commands;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main() {
    cin >> commands;
    int x=0;
    int y=0;

    int dir=0;
    int cnt=0;
    for(int i=0;i<commands.length();i++){
        if(commands[i]=='F'){
            x+=dx[dir];
            y+=dy[dir];
            cnt++;
            if(x==0&&y==0){
                // 지금까지의 시간 출력
                cout<<cnt;
                return 0;
            }
            
        }else if(commands[i]=='L'){
            dir=(dir+3)%4;
            cnt++;
        }else if(commands[i]=='R'){
            dir=(dir+1)%4;
            cnt++;
        }
    }
    if(x!=0||y!=0){
        cout<<-1;
    }
    return 0;
}