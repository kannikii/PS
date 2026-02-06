#include <iostream>
using namespace std;
// 완전 순열 : 순열 배치에서 이전과 같은 위치에 재배치 되는 원소가 1개도 없는 순열
static long long D[1000001];
static int mod = 1000000000;
int main() {
    int N;
    cin>>N;
    // D[N] = 각 사람별 선물을 받을 수 있는 경우의 수 
    // 선물 교환하는 방식 2가지 (A->B 주고난 경우)
    // 1. A->B B->A (양방향 교환) D[N-2] (A,B 두명이 받을 선물이 정해짐)
    // 2. A->B B는 다른 사람에게 D[N-1] (B만 받을 선물이 정해짐)

    // 완전 순열 점화식
    // D[N] = (N-1) * (D[N-2] + D[N-1])
    // N-1 : A가 선물의 줄 수 있는 경우의 수
    // D[N-2], D[N-1] : 선물 교환하는 방식 2가지

    D[1]=0;
    D[2]=1;

    for(int i=3;i<=N;i++){
        D[i]=(i-1)*(D[i-2]+D[i-1])%mod;
    }

    cout<<D[N]<<"\n";
}