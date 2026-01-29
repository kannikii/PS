#include <iostream>
#include <queue>
#include <vector>

// 최소 신장 트리 (Minimum Spanning Tree)
// 1. 에지 리스트로 그래프 구현, 유니온 파인드 배열 초기화
// 2. 그래프 데이터를 가중치 기준으로 정렬
// 3. 가중치가 낮은 에지부터 연결 시도
// 4. 3번 과정 연결 에지 개수가 N-1까지 반복
// 5. 총 에지 비용 출력
using namespace std;
typedef struct Edge {
    int s,e,v;
    bool operator > (const Edge& temp) const {
        return v > temp.v;
    }
}Edge;  // 에지 정보 구조체, 가중치 값 기준 오름차순 정렬로 설정
static vector<int> parent;
void unionfunc(int a, int b);
int find(int a);
int main() {
    int V,E;
    cin>>V>>E;
    priority_queue<Edge,vector<Edge>,greater<Edge>> pq; // 오름차순 정렬
    parent.resize(V+1);

    for(int i=0;i<E;i++){
        int A,B,C;
        cin>>A>>B>>C;
        pq.push(Edge{A,B,C});
    }

    for(int i=0;i<=V;i++){
        parent[i]=i;
    }

    int useEdge=0; // V-1 되면 반복 종료

    int result =0;

    while(useEdge<V-1){
        Edge now = pq.top();
        pq.pop();
        // 같은 부모가 아니라면 -> 연결해도 사이클이 생기지 않는 다면
        if(find(now.s)!=find(now.e)){
            unionfunc(now.s,now.e);
            result+=now.v;
            useEdge++;
        }
    }
    cout<<result<<"\n";
}

void unionfunc(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        parent[b]=a;
    }
}
int find(int a) {
    if(a==parent[a]) return a;
    else{
        return parent[a]=find(parent[a]);
    }
}