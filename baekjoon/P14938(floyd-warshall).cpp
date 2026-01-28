#include <iostream>
#include <climits>
#include <vector>

using namespace std;
static int N,M,R;
static vector<int> items;
int main() {
    cin>>N>>M>>R;
    items.resize(N+1);
    for(int i=1;i<=N;i++){
        cin>>items[i];
    }
    long D[101][101];
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(i==j) D[i][j]=0;
            else D[i][j]=INT_MAX;
        }
    }
    for (int i = 0; i < R; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        D[a][b] = min(D[a][b], (long)l);
        D[b][a] = min(D[b][a], (long)l);
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=N;k++){
                if(D[j][i]!=INT_MAX&&D[i][k]!=INT_MAX) {
                    D[j][k]=min(D[j][k],D[j][i]+D[i][k]);
                }
            }
        }
    }
    int answer=-1;
    for(int i=1;i<=N;i++){
        int sum=0;
        for(int j=1;j<=N;j++){
            if(D[i][j]<=M){
                sum+=items[j];
            }

        }
        answer=max(answer,sum);
    }
    cout<<answer<<"\n";
}