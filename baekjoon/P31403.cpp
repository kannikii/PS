#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int A, B, C;

    cin >> A >> B >> C;
    cout << A + B - C << "\n";

    // B의 자리수 계산해서 10^digits만큼 A에 곱하고 B를 더하고 C를 뺌
    // A*10^digits+B-C
    int digits = 0;
    int originB = B;

    while (B > 0) {
        B = B / 10;
        digits++;
    }

    int ten = 1;
    for (int i = 0; i < digits; i++) ten *= 10;
    cout << A * ten + originB - C << "\n";

}