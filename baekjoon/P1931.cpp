#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].second;  // 시작시간
        cin >> A[i].first;   // 종료시간
    }
    // 종료시간이 짧은것 순서로 오름차순 정렬 , 
    // 종료 시간이 같을 경우 시작시간이 짧은것부터 정렬
    sort(A.begin(), A.end());
    int cnt = 0;
    int end = -1;
    for (int i = 0; i < N; i++) {
        if (A[i].second >= end) {   // 다음 회의의 시작시간이 지금까지의 회의의 종료시간보다 늦은 경우
            end = A[i].first;       // 다음 회의의 종료시간으로 종료시간 업데이트
            cnt++;
        }
    }
    cout << cnt << "\n";
}