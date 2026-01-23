#include <iostream>
#include <vector>
#include <climits>
#include <tuple>

using namespace std;

// 벨만-포드 최단 경로 알고리즘
// 1. 출발 노드 설정 D[s]=0;
// 2. 최단 거리 테이블 D[] 초기화
// 3. 다음의 과정을 N-1번 반복
    // a. 전체 간선 E개를 하나씩 확인
    // b. 각 간선을 거쳐 다른 노드로 가는 비용을 계산하여 최단 거리 테이블을 갱신한다.
// 4. 만약 음수 간선 순환이 발생하는지 확인하려면 3번의 과정을 한 번 더 수행한다.
    // 이때 최단 거리 테이블이 갱신되면 음수 간선 순환이 존재한다.
typedef tuple<int,int,int> edge;
static vector<edge> edges;
int main() {
    int N,M;
    cin>>N>>M;

    for(int i=1;i<=M;i++){
        int A,B,C;
        cin>>A>>B>>C;
        edges.push_back({A,B,C});
    }
    // [1],[2]
    vector<int> D(N+1,INT_MAX);
    D[1]=0;

    // [3]
    for(int i=1;i<N;i++){
        for(int j=0;j<M;j++){
            edge medge=edges[j];
            int start = get<0>(medge);
            int end = get<1>(medge);
            int time = get<2>(medge);

            if(D[start]!=INT_MAX&&D[end]>D[start]+time){
                D[end]=D[start]+time;
            }

        }
    }
    bool mCycle = false;

    // [4]
    for(int i=0;i<M;i++){
        edge medge=edges[i];
        int start = get<0>(medge);
        int end = get<1>(medge);
        int time = get<2>(medge);
        if(D[start]!=INT_MAX&&D[end]>D[start]+time){
            mCycle=true;
        }
    }

    if(!mCycle){
        for(int i=2;i<=N;i++){
            if(D[i]==INT_MAX){
                cout<<-1<<"\n";
            }
            else{
                cout<<D[i]<<"\n";
            }
        }
    }
    else{
        cout<<-1<<"\n";
    }
}