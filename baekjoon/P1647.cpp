#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef struct Edge{
    int s,e,v;
    bool operator > (const Edge& temp) const {
        return v > temp.v;
    }
}Edge;
static priority_queue<Edge,vector<Edge>,greater<Edge>> pq; 
static vector<int> parent;

void unionfunc(int a, int b);
int find(int a);
// 일단 MST를 만든다 (N−1개의 간선)
// 그 MST에서 가장 비싼 간선 하나를 제거한다

// 그러면,
// 트리가 정확히 두 개로 쪼개짐
// 각 트리는 내부적으로 최소 비용 유지

// 방법 1: 하나의 마을에서 가장 비싼 간선 하나 빼서 출력
// 방법 2: N-1번 반복이 아닌 N-2번 반복만 하기 (간선 하나 안쓰기)(오름차순이므로 가장긴 것 안씀) 
int main() {
    int N;
    cin>> N;
    parent.resize(N+1);
    for(int i=0;i<=N;i++){
        parent[i]=i;
    }
    int M;
    cin>>M;

    for(int i=0;i<M;i++){
        int A,B,C;
        cin>>A>>B>>C;
        pq.push({A,B,C});
    }

    int useEdge=0;
    int result =0;

    while(!pq.empty()&&useEdge<N-2){
        Edge now = pq.top();
        pq.pop();
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
int find(int a){
    if(a==parent[a]){
        return a;
    }else{
        return parent[a]=find(parent[a]);
    }
}