#include <iostream>
#include <vector>
using namespace std;

struct Edge{
    int endNode;
    int value;
};

int main(){
    // 이차원 벡터 초기화
    vector<vector<Edge>> A;
    int N, E;
    cin >> N >> E;
    A.resize(N + 1);

    // A[i] = { {endNode, value}, {endNode, value}, ... }

    // 그래프 데이터 저장하기
    for (int i = 0; i < E; i++){
        int s, e, v = 0;
        cin >> s >> e >> v;
        A[s].push_back({e, v});
    }

    // 그래프 데이터 가져오기
    for (int i = 1; i <= N; i++){
        if (A[i].empty())
            continue;
        cout << "출발노드 " << i << ":\n";

        // 중요! A[i]안의 Edge하나씩 꺼내서 edge라는 이름으로 반복 처리
        for (Edge edge : A[i]){
            cout << "  -> 도착노드: " << edge.endNode
                 << ", 가중치: " << edge.value << '\n';
        }
        // for (int j = 0; j < A[i].size(); j++){
        //     Edge edge = A[i][j];
        //     cout << "  -> 도착노드: " << edge.endNode
        //         << ", 가중치: " << edge.value << '\n';
        // }

        cout << "\n";
    }
}