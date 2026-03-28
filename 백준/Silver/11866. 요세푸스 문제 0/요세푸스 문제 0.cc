#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 코드 작성
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> A;
    for (int i = 1; i <= N; i++) {
        A.push_back(i);
    }

    vector<int> B;
    int idx = 0;
    int K;
    cin >> K;

    while (!A.empty()) {
        idx = (idx + K - 1) % A.size();
        B.push_back(A[idx]);
        A.erase(A.begin() + idx);
    }

    cout << "<";
    for (int i = 0; i < B.size(); i++) {
        cout << B[i];
        if (i != B.size() - 1) cout << ", ";
    }
    cout << ">";
	
    return 0;
}