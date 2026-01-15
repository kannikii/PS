#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int min, max;
    cin >> min >> max;
    vector<int> A(max + 1, 0);
    for (int i = 2; i <= max; i++) {
        A[i] = i;
    }
    for (int i = 2; i <= sqrt(max); i++) {
        if (A[i] == 0) continue;
        for (int j = i + i; j <= max; j += i) {
            A[j] = 0;
        }
    }
    int sum = 0;
    int answer = 0;

    for (int i = min; i <= max; i++) {
        if (A[i] != 0) {
            answer = A[i];
            break;
        }
    }
    for (int i = min; i <= max; i++) {
        if (A[i] != 0) {
            sum += A[i];
        }
    }

    if (sum == 0) {
        cout << -1 << "\n";
    } else {
        cout << sum << "\n";
        cout << answer << "\n";
    }
}