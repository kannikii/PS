#include <iostream>
#include <map>

using namespace std;

int main() {
    // 코드 작성
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 단순 반복 비교는 O(N^2)이라 안됨
    // 저장을 map으로 해서 N개의 숫자 값들을 인덱스로 쓰고, 입력이 추가될때
    // 개수를 +1해줌 조회시 O(1)

    int N;
    cin >> N;

    map<int, int> n;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        n[a] ++;
    }
    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;
        cout << n[b] << " ";
    }

    return 0;
}