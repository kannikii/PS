#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string N;
    cin >> N;

    int count = 0;
    int temp;

    for (int i = 0; i < 12; i++) {
        if (N[i] == '*') {
            temp = i;
            continue;
        }

        if (i % 2 == 0) {
            count += (N[i] - '0');
        } else {
            count += (N[i] - '0') * 3;
        }
    }

    int last = N[12] - '0';
    int k = (10 - (count + last) % 10) % 10;

    int x;
    if (temp % 2 == 0) {
        x = k;
    } else {
        x = (7 * k) % 10;
    }

    cout << x << "\n";
    return 0;
}