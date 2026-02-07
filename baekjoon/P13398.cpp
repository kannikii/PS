#include <algorithm>
#include <iostream>
using namespace std;

// 구간합 배열 작성 -> 연속된 숫자의 합...
// 모든 가능한 구간에 대해 최댓값 구간합 연산하면서 갱신하기 힘들다.. 시간이
// 오래걸림.. 어떻게 해야할까?

// 문제를 나눠 생각해보자
// 우선 수를 하나도 제거하지 않는 것부터 생각
// 연속합 (Kadane's Algorithm)
// i번째 원소를 반드시 포함하는 최대 연속합은
// i-1번째 까지의 연속합에 이어 붙이거나
// i부터 새로 시작하거나 둘 중 큰 값이다.
static int sqc[100001];
static int D[100001][2];
// D[i][0] i번째로 끝나는(i포함i가 마지막인) 부분 행렬의 최댓값 
// [0/1]숫자를 제거하지 않은경우/제거 한 경우
int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> sqc[i];
    }

    // 제거하지않고 온 경우
    // D[i][0]=max(D[i-1][0]+sqc[i],sqc[i])
    // 제거를 과거에 끝낸경우
    // D[i][1]=D[i-1][1]+sqc[i];
    // i번째를 제거하는 경우
    // D[i][1]=D[i-1][0]
    // 제거하는 경우 둘 중 더 큰 값을 저장하면 된다. max()사용

    D[1][1] = 0;
    D[1][0] = sqc[1];
    long long max_sum = sqc[1];
    long long now_sum = 0;
    for (int i = 2; i <= N; i++) {
        D[i][0] = max(D[i - 1][0] + sqc[i], sqc[i]);
        D[i][1] = max(D[i - 1][0], D[i - 1][1] + sqc[i]);
        now_sum = max(D[i][0], D[i][1]);
        if (max_sum < now_sum) {
            max_sum = now_sum;
        }
    }

    cout << max_sum << "\n";
}