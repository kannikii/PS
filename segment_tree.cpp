#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
static vector<int> tree;
static vector<int> treeA;
static vector<int> treeB;
static vector<int> treeC;
// 구간합 -> 세그먼트 트리 
// 구간합을 구하는 질의가 매우 많고, 요소의 변화가 자주 있다면 세그먼트 트리
int main() {
    // 1. 트리 초기화
    int N;  // 입력 데이터 개수
    cin >> N;
    int k=0;
    // 2ᵏ>=N을 만족하는 k에 대하여 2ᵏ * 2 크기로 설정
    while((1<<k)<N) k++;

    tree.resize(pow(2, k + 1));
    treeA.resize(pow(2, k + 1));
    treeB.resize(pow(2, k + 1));
    treeC.resize(pow(2, k + 1));
    
    // 리프 노드 입력
    for (int i = pow(2, k); i < tree.size(); i++) {
        cin >> tree[i];
        treeA[i]=treeB[i]=treeC[i]=tree[i];
    }
    // 나머지 리프는 0 / -inf / inf 처리
    for (int i = (1 << k) + N; i < tree.size(); i++) {
        treeA[i] = 0;
        treeB[i] = -1e9;
        treeC[i] = 1e9;
    }

    // 구간 합 세그먼트 트리
    for (int i = 1; i < pow(2, k); i++) {
        treeA[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    // 최대 트리
    for (int i = 1; i < pow(2, k); i++) {
        treeB[i] =max(tree[i * 2] , tree[i * 2 + 1]);
    }
    // 최소 트리
    for (int i = 1; i < pow(2, k); i++) {
        treeC[i] =min(tree[i * 2] , tree[i * 2 + 1]);
    }
    // 2. 질의값 구하기
    // 세그먼트 트리 index = 질의 index +2ᵏ-1

    // 노드 선택 과정
    // 1. start_index % 2 == 1 일 때 해당 노드 선택
    // 2. end_index % 2 == 0 일 때 해당 노드 선택
    // 3. start_index depth 변경 : start_index = (start_index+1)/2 연산 수행
    // 4. end_index depth 변경 : end_index = (end_index -1) /2 연산 수행
    // 5. 1~4번 반복하다가 end_index < start_index 되면 종료

    // 질의에 따른 노드 연산 방법
    // - 구간 합 : 선택된 노드들 모두 더하여 출력
    // - 최댓값 구하기 : 선택된 노드 중 MAX 값을 선택해 출력
    // - 최솟값 구하기 : 선택된 노드 중 MIN 값을 선택해 출력

    // =========================
    // 예시: l ~ r 구간 합 구하기
    // =========================

    int l;
    int r;
    cin>> l>>r;

    int start_index = l + (1 << k) - 1;
    int end_index = r + (1 << k) - 1;

    int sum = 0;

    while (start_index <= end_index) {
        if (start_index % 2 == 1) {
            sum += treeA[start_index];
            start_index++;
        }
        if (end_index % 2 == 0) {
            sum += treeA[end_index];
            end_index--;
        }
        start_index /= 2;
        end_index /= 2;
    }

    cout << "구간 합 (l ~ r): " << sum << '\n';

    return 0;
    // 3. 데이터 업데이트하기
    // 최댓값/최솟값 찾기는 같은 부모의 다른 자식과 비교해서 최대/최소 값이 업데이트(좌,우)되지 않으면 중단
}