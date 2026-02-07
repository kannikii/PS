#include <iostream>
#include <algorithm>
using namespace std;
static int sqc[100001];
static int D[100001];
// D[i] i번째로 끝나는(i포함i가 마지막인) 부분 행렬의 최댓값 

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> sqc[i];
    }
    D[1]=sqc[1];
    long long sum_max=sqc[1];
    for(int i=2;i<=N;i++){
        D[i]=max(D[i-1]+sqc[i],sqc[i]);
        if(sum_max<D[i]){
            sum_max=D[i];
        }
    }
    cout<<sum_max<<"\n";
}
