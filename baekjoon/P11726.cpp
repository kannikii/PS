#include <iostream>
using namespace std;
static int mod = 10007;
static int D[1001]; // D[i]=2xi크기의 직사각형을 채우는 방법의 수
int main() {
    int N;
    cin>>N;

    D[1]=1;
    D[2]=2;
    // D[3]=3;
    // D[4]=5;
    // D[5]=8;
    for(int i=3;i<=N;i++){
        D[i]=(D[i-1]+D[i-2])%mod;
    }
    cout<<D[N]<<"\n";
}