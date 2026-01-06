#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> input(8, 0);
vector<int> sorted(8, 0);
int main() {
    for (int i = 0; i < 8; i++) {
        cin >> input[i];
    }

    vector<int> asc = input;
    vector<int> desc = input;

    sort(asc.begin(), asc.end());
    sort(desc.begin(), desc.end(), greater<int>());

    if (input == asc) {
        cout << "ascending\n";
    } else if (input == desc) {
        cout << "descending\n";
    } else {
        cout << "mixed\n";
    }
}