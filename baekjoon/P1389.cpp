#include <iostream>
#include <climits>

using namespace std;

int main() {
    int N,M;
    cin>>N>>M;
    long D[101][101];
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(i==j) D[i][j]=0;
            else D[i][j]=INT_MAX;
        }
    }
    for(int i=0;i<M;i++){
        int A,B;
        cin>>A>>B;
        D[A][B]=1;
        D[B][A]=1;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=N;k++){
                if(D[j][k]>D[j][i]+D[i][k]){
                    D[j][k]=D[j][i]+D[i][k];
                }
            }
        }
    }
    int Min=INT_MAX;
    int Answer=-1;

    for(int i=1;i<=N;i++){
        int tmp=0;
        for(int j=1;j<=N;j++){
            tmp+=D[i][j];
        }
        if(Min>tmp){
            Min=tmp;
            Answer=i;
        }
    }
    cout<<Answer<<"\n";
}