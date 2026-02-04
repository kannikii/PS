#include <iostream>
#include <vector>
#include <queue>
// 최소 공통 조상 구하기
// 인접 리스트 트리 
using namespace std;
static vector<bool> visited;
static vector<int> parent;
static vector<int> depth;

static vector<vector<int>> tree;
void BFS(int root);
void LCA(int c, int d);
int main() {
    int N;
    cin>>N;
    tree.resize(N+1);
    depth.resize(N+1);
    parent.resize(N+1);

    visited=vector<bool>(N+1,false);
    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    int M;
    cin>>M;
    BFS(1); // 루트 노드 부터 각 노드 별 깊이 구하는 탐색 시작
    for(int i=0;i<M;i++){
        int c,d;
        cin>>c>>d;
        LCA(c,d);
    }
}
// 최소 공통 조상 찾기 
void LCA(int c, int d){
    if(depth[c]<depth[d]){
        int temp=c;
        c=d;
        d=temp;
    }
    while(depth[c]!=depth[d]){
        c=parent[c];
    }
    // c를 올려서 같은 깊이로 만듬

    while(c!=d){
        c=parent[c];
        d=parent[d];
    }
    // 같아 질때까지 부모 찾음
    
    cout<< c<<"\n";
}
// BFS/DFS로 각 노드의 깊이를 구함
void BFS(int root) {
    queue<int> q;
    q.push(root);
    visited[root] = true;
    depth[root] = 0;
    parent[root] = 0;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int next : tree[now]) {
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = now;
                depth[next] = depth[now] + 1;
                q.push(next);
            }
        }
    }
}

// void BFS(int node){
//     queue<int> myQueue;
//     myQueue.push(node);
//     visited[node]=true;

//     int level=1;
//     int count =0;
//     int now_size=1;

//     while(!myQueue.empty()){
//         int now=myQueue.front();
//         myQueue.pop();

//         for(int next: tree[now]){
//             if(!visited[next]){
//                 visited[next]=true;
//                 myQueue.push(next);
//                 parent[next]=now;
//                 depth[next]=level;
//             }
//         }
//         count++;
//         if(count==now_size){
//             count=0;
//             now_size=myQueue.size();
//             level++;
//         }
//     }

// }
