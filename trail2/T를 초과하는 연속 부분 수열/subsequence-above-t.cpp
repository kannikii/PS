#include <iostream>
#include <algorithm>
using namespace std;

int n, t;
int arr[1000];

int main() {
    cin >> n >> t;
    int cnt=0;
    int maxC=0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > t) {
            cnt++;
        }
        else {
            cnt = 0;
        }

        maxC = max(maxC, cnt);
    }

    cout<<maxC;

    return 0;
}