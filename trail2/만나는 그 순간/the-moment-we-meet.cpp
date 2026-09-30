#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
char d[1000];
int t[1000];

char d2[1000];
int t2[1000];

int a[1000001];
int b[1000001];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> d[i] >> t[i];

    for (int i = 0; i < m; i++)
        cin >> d2[i] >> t2[i];

    // A의 시간별 위치 기록
    int nowA = 0;
    int timeA = 0;

    for (int i = 0; i < n; i++) {
        if (d[i] == 'R') {
            for (int j = 0; j < t[i]; j++) {
                nowA++;
                timeA++;
                a[timeA] = nowA;
            }
        }
        else {
            for (int j = 0; j < t[i]; j++) {
                nowA--;
                timeA++;
                a[timeA] = nowA;
            }
        }
    }

    // B의 시간별 위치 기록
    int nowB = 0;
    int timeB = 0;

    for (int i = 0; i < m; i++) {
        if (d2[i] == 'R') {
            for (int j = 0; j < t2[i]; j++) {
                nowB++;
                timeB++;
                b[timeB] = nowB;
            }
        }
        else {
            for (int j = 0; j < t2[i]; j++) {
                nowB--;
                timeB++;
                b[timeB] = nowB;
            }
        }
    }

    // 1초부터 비교
    for (int i = 1; i <= timeA; i++) {
        if (a[i] == b[i]) {
            cout << i;
            return 0;
        }
    }

    cout << -1;

    return 0;
}