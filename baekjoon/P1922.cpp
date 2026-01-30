#include <iostream>
#include <queue>
#include <vector>

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

using namespace std;

int main() {
    int N;
    cin>> N;
    int M;
    cin>> M;
    parent.resize(N+1);
    for(int i=0;i<=N;i++){
        parent[i]=i;
    }
    for(int i=0;i<M;i++){
        int A,B,C;
        cin>>A>>B>>C;
        pq.push({A,B,C});
    }
    // 필요한 최소 간선의 수 M
    int useEdge=0; // M까지 반복
    int result =0;
    while(!pq.empty()&&useEdge<M){
        Edge now = pq.top();
        pq.pop();
        // 연결하려는 노드들의 부모가 서로 같은경우는 연결 하지 않음 (사이클)
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