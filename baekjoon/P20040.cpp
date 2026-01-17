#include <iostream>

using namespace std;
static int parent[500001];
void unionfunc(int a, int b);
int find(int a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        parent[i]=i;
    }

    for (int i = 1; i <= M; i++) {
        int a,b;
        cin>>a>>b;

        // 사이클이 생성되면 i번째 임을 출력하고 프로그램 종료
        if (find(a) == find(b)) {
            cout << i << "\n";
            return 0;
        }

        unionfunc(a,b);
    }
    cout << 0 << "\n";
    return 0;
}
void unionfunc(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}
int find(int a) {
    if (a == parent[a]) {
        return a;
    } else {
        return parent[a] = find(parent[a]);
    }
}