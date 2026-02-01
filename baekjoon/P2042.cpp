#include <iostream>
#include <vector>
using namespace std;

static int k = 0;
static vector<long long> tree;

void update(int idx, long long val);
void prefixSum(int l, int r);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    while ((1 << k) < N) k++;
    int base = 1 << k;
    tree.resize(base * 2);

    // 리프 입력
    for (int i = 0; i < N; i++) {
        cin >> tree[base + i];
    }

    // 내부 노드 빌드
    for (int i = base - 1; i >= 1; i--) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    // 쿼리 처리
    for (int i = 0; i < M + K; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int b;
            long long c;
            cin >> b >> c;
            update(b, c);
        } else {
            int b, c;
            cin >> b >> c;
            prefixSum(b, c);
        }
    }
}

void update(int idx, long long val) {
    int pos = idx + (1 << k) - 1;
    tree[pos] = val;

    // 부모로 갱신 전파
    pos /= 2;
    while (pos >= 1) {
        tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
        pos /= 2;
    }
}

void prefixSum(int l, int r) {
    int start_index = l + (1 << k) - 1;
    int end_index = r + (1 << k) - 1;

    long long sum = 0;

    while (start_index <= end_index) {
        if (start_index % 2 == 1) {
            sum += tree[start_index++];
        }
        if (end_index % 2 == 0) {
            sum += tree[end_index--];
        }
        start_index /= 2;
        end_index /= 2;
    }

    cout << sum << '\n';
}
