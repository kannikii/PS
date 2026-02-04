#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
static int N,M;
static vector<vector<int>> tree;
static vector<int> depth;
static int kmax;
static int parent[21][100001];
static vector<bool> visited;
void LCA(int a, int b);
void BFS(int root);

// LCA2 최소 공통 조상 빠르게 구하기
// LCA의 기본은 1. 서로의 깊이를 맞추고 2. 같아지는 노드를 찾을때까지 올라가는 방식
// 빠르게 하는 방법은 한 칸씩올라가는 것이 아니라, 2ᵏ칸씩 올라간다.
// 자신의 부모 노드만 저장해 놓던 방식에서
// 2ᵏ번째 위치의 부모 노드까지 저장해 두어야 한다.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    tree.resize(N+1);

    for(int i=0;i<N-1;i++){
        int s,e;
        cin>>s>>e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    depth.resize(N+1);
    visited.resize(N+1);

    kmax = 0;
    while((1 << kmax) <= N) kmax++;  // 2^kmax > N
    BFS(1); // K=0 인 부분 채우는 과정
    
    // 점화식을 이용한 부모 배열 채우기
    for(int k=1;k<=kmax;k++){
        for(int n=1;n<=N;n++){
            parent[k][n]=parent[k-1][parent[k-1][n]];
        }
    }

    cin>>M;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        LCA(a,b);
    }



    
}
void LCA(int a, int b){
    if(depth[a]>depth[b]){
        int temp=a;
        a=b;
        b=temp;
    }   // a가 항상 b보다 깊이 작은 걸로 통일하여 계산하도록 함

    // 높이 차이 만큼 완성되어있는 P[][]배열 값을 확인해서 바로 올라간다.
    // 2ᵏ<=높이 차이 의 최대 K 만큼 한번에 올라간다.
    for(int k=kmax; k>=0;k--){  // 깊이 서로 근접하게 빠르게 맞추기 (2ᴷ만큼 올라오며)
        if(pow(2,k)<=depth[b]-depth[a]){
            if(depth[a]<=depth[parent[k][b]]){
                // 올라갔는데도 여전히 a보단 아래이면 멈추고 여기까지 올라온것으로 처리
                b=parent[k][b];
            }
        }
    }
    // 제일 큰 K값부터 2ᴷ단위로 점프해서 동일하다면 K-1번째로 내려가서 확인해보고, 
    // 다르다면 여기서 또 K-1 -1 번째 값을 확인해보고 동일해지면 멈춘다. 
    for(int k=kmax;k>=0&&a!=b;k--){
        if(parent[k][a]!=parent[k][b]){
            a=parent[k][a];
            b=parent[k][b];
        }
    }
    int lca=a;

    if(a!=b){
        lca=parent[0][lca];
    }
    cout<<lca<<"\n";
}

void BFS(int root){
    queue<int> q;
    q.push(root);
    visited[root]=true;
    depth[root] = 0;
    parent[0][root] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();

        for (int next : tree[now]) {
            if (!visited[next]) {
                visited[next] = true;
                parent[0][next] = now;
                depth[next] = depth[now] + 1;
                q.push(next);
            }
        }

    }
}