#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin>>N>>M;
    int a[1025][1025]={};
    int S[1025][1025]={};
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>a[i][j];
            //합 배열 구하기
            S[i][j]=S[i][j-1]+a[i][j];
        }
    }
    for(int i=1;i<=M;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        //합 배열에서 값 뽑아내기
        int sum=0;
        for(int yl=y1;yl<=y2;yl++){
            sum+=S[yl][x2]-S[yl][x1-1];
        }
        cout<<sum<<"\n";
    }
}