#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int base = -1;

    for (int i = 0; i < 3; i++) {
        cin >> s;
        if (isdigit(s[0])) {
            base = stoi(s) - i;
        }
    }

    int next = base + 3;

    if (next % 15 == 0) cout << "FizzBuzz\n";
    else if (next % 3 == 0) cout << "Fizz\n";
    else if (next % 5 == 0) cout << "Buzz\n";
    else cout << next << "\n";

    return 0;
}