#include <iostream>
using namespace std;
static int D[31][31];
int main() {
    int T;
    cin>>T;
    for(int i=0;i<31;i++){
        D[i][0]=1;
        D[i][i]=1;
        D[i][1]=i;
    }
    for(int i=1;i<31;i++){
        for(int j=1;j<i;j++){
            D[i][j]=D[i-1][j]+D[i-1][j-1];
        }
    }

    while(T>0){
        int N,M;
        cin>>N>>M;
        // M개 중에 다리가 놓아질 N개 선택하기 -> 조합
        cout<<D[M][N]<<"\n";
        T--;
    }
}