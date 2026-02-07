#include <iostream>
#include <cmath>
using namespace std;
static long long mod=1000000000;
static long long D[101][11];    // D[i][0~9] : 길이가 i, 끝자리 수가 0~9인 계단수의 개수
int main() {
    int N;
    cin>>N;
    D[1][0]=0;
    for(int i=1;i<=9;i++){
        D[1][i]=1;
    }
    for(int i=1;i<=N;i++){
        D[i][10]=0;
    }
    // D[2][0]=1;
    // D[2][1]=D[1][2]+D[1][0];
    // D[2][2]=D[1][1]+D[1][3];
    // ...
    // D[2][8]=D[1][7]+D[1][9];
    // D[2][9]=D[1][8]+D[1][10];
    for(int i=2;i<=N;i++){
        D[i][0]=D[i-1][1];
        for(int j=1;j<=9;j++){
            D[i][j]=(D[i-1][j-1]+D[i-1][j+1])%mod;
        }
    }
    // 10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98  -> 17 개
    // 1~8까지 숫자 뒤에 올 수 있는 수 2개씩 9는 1개뿐 
    long long result=0;
    for(int i=0;i<=9;i++){
        result+=D[N][i];
    }
    cout<<(result%mod)<<"\n";
}