#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
int student[10000];

int main() {
    cin >> N >> M >> K;
    vector<int> v(N+1,0);
    // v[N] : N번째 학생의 벌칙 횟수
    // 값이 K보다 크게 되는 순간 벌금 
    // 매번 검사해야하나?
    for (int i = 0; i < M; i++) {
        cin >> student[i];
        v[student[i]]++;
        if(v[student[i]]>=K){
            cout<<student[i];
            return 0;
        }
    }
    cout<<-1;

    return 0;
}