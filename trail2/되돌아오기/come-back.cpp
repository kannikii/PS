#include <iostream>

using namespace std;

int N;
char dir[100];
int dist[100];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main() {
    cin >> N;
    int x=0;
    int y=0;
    int cnt=0;

    for (int i = 0; i < N; i++) {
        cin >> dir[i] >> dist[i];

        if(dir[i]=='N'){
            for(int j=0;j<dist[i];j++){
                x=x+dx[0];
                y=y+dy[0];
                cnt++;
                if(x==0 && y==0){
                    cout<<cnt;
                    return 0;
                }
            }
        }else if(dir[i]=='S'){
            for(int j=0;j<dist[i];j++){
                x=x+dx[2];
                y=y+dy[2];
                cnt++;
                if(x==0 && y==0){
                    cout<<cnt;
                    return 0;
                }
            }
        }else if(dir[i]=='E'){
            for(int j=0;j<dist[i];j++){
                x=x+dx[1];
                y=y+dy[1];
                cnt++;
                if(x==0 && y==0){
                    cout<<cnt;
                    return 0;
                }
            }
        }else if(dir[i]=='W'){
            for(int j=0;j<dist[i];j++){
                x=x+dx[3];
                y=y+dy[3];
                cnt++;
                if(x==0 && y==0){
                    cout<<cnt;
                    return 0;
                }
            }
        }
    }

    if(x!=0 || y!=0){
        cout<<-1;
    }

    

    

    return 0;
}