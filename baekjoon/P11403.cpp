#include <iostream>
#include <climits>
using namespace std;
int main() {
    int N;
    cin>>N;
    long D[101][101];
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(i==j)D[i][j]=0;
            else D[i][j]=INT_MAX;
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>D[i][j];
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=N;k++){
                if(D[j][i]==1&&D[i][k]==1){
                    D[j][k]=1;
                }
            }
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<D[i][j]<<" ";
        }
        cout<<"\n";
    }
}