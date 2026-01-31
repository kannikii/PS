#include <iostream>
#include <vector>

using namespace std;
static vector<int> parent;
static vector<vector<int>> tree;
static vector<bool> visited;
static int leafNode = 0;
static int removeNode;
void DFS(int node);
int main() {
    int N;
    cin >> N;
    parent = vector<int>(N, -1);
    visited = vector<bool>(N, false);
    tree.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> parent[i];
    }

    int rootNode = 0;
    // 인접리스트로 트리 구현
    for (int i = 0; i < N; i++) {
        if (parent[i] == -1) {
            rootNode = i;
        }
        if (parent[i] != -1) {
            tree[parent[i]].push_back(i);
            tree[i].push_back(parent[i]);
        }
    }
    cin >> removeNode;
    if (removeNode == rootNode) {
        cout << 0 << "\n";
    } else {
        DFS(rootNode);
        cout << leafNode << "\n";
    }
}
// DFS 탐색 하며 리프노드 개수 세기
// 삭제할 노드 만나면 탐색 중단
void DFS(int node) {
    // 하나씩 탐색할 때마다 리프 노드 세기
    visited[node] = true;
    int childNode = 0;
    for (int i : tree[node]) {
        if (!visited[i] && i != removeNode) {
            childNode++;
            DFS(i);
        }
    }
    if (childNode == 0) {
        leafNode++;
    }
}