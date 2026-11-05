#include <iostream>
#include <vector>
using namespace std;

int n;
int cnt = 0;
vector<int> answer;

bool isBeautiful() {
    int i = 0;                          // 현재 묶음의 시작 위치
    while (i<n) {
        int d = answer[i];              // 이 묶음의 숫자 = 묶음 크기

        if (i+d-1>n) return false;

        for (int j = i; j < i + d; j++) {
            if (answer[j]!=d) return false;
        }

        /* ⬅ ④ 다음 묶음의 시작 위치로 점프 */
        i=i+d;
    }
    return true;                        
}

void choose(int cur) {
    if (cur > n) {
        if (isBeautiful()) cnt++;
        return;
    }
    for (int i = 1; i <= 4; i++) {
        answer.push_back(i);
        choose(cur+1);
        answer.pop_back();
    }
}

int main() {
    cin >> n;
    choose(1);
    cout << cnt;
    return 0;
}