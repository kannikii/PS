#include <iostream>

using namespace std;

int main() {
    int level = 1;
    int limit = 1;
    int N;
    cin >> N;

    // 1개,6개,12개,18개,24개 단위로 레벨 결정 (1,2,3,4,5,...)
    while (N > limit) {
        limit += 6 * level;
        level++;
    }

    cout << level << "\n";
}