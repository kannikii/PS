#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<string> v(N + 1); // 1번부터 쓰기 위해 N+1
    unordered_map<string, int> m;

    // 포켓몬 입력
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        m[v[i]] = i;
    }

    // 질문 처리
    while (M--) {
        string query;
        cin >> query;

        // 숫자인지 판별
        if (isdigit(query[0])) {
            int idx = stoi(query);
            cout << v[idx] << '\n';
        } else {
            cout << m[query] << '\n';
        }
    }

    return 0;
}