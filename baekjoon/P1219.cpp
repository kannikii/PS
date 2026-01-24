#include <iostream>
#include <vector>
#include <climits>
#include <tuple>
using namespace std;

/*
    BOJ 1219 오민식의 고민

    핵심 아이디어:
    - 벨만–포드를 "최대 이익" 문제로 변형
    - D[x] = x 도시에 도착했을 때 가질 수 있는 최대 돈
    - 돈을 무한히 벌 수 있는 사이클이 있고,
      그 사이클에서 도착점 E로 갈 수 있으면 "Gee"
    - 아예 도착 불가능하면 "gg"
*/

typedef tuple<int,int,int> edge;
static vector<edge> edges;

// earn[i] : i번 도시에 방문할 때 얻는 수익
static vector<long> earn;

// D[i] 상태 의미:
// LONG_MIN : 아직 도달 불가능
// 유한값    : 유한한 최대 수익
// LONG_MAX : 무한히 돈을 벌 수 있음 (양의 사이클 영향)
static vector<long> D;

int main() {
    int N,S,E,M;
    cin>>N>>S>>E>>M;

    earn.resize(N,0);
    D.resize(N,LONG_MIN);

    // 교통 수단 입력 (단방향)
    // 실제 계산에서는 (수익 - 비용) 형태로 사용됨
    for(int i=0;i<M;i++){
        int src,dst,cost;
        cin>>src>>dst>>cost;
        edges.push_back({src,dst,cost});
    }

    // 각 도시 방문 시 얻는 수익
    for(int i=0;i<N;i++){
        cin>>earn[i];
    }

    // 시작 도시에서는 이동 없이도 해당 도시 수익을 얻음
    D[S]=earn[S];

    /*
        벨만–포드 수행
        - 처음 N-1번: 정상적인 최대 이익 계산
        - 이후 반복: 양의 사이클(무한 이익) 영향 전파
        - N+50은 충분한 여유 반복 횟수
    */
    for(int i=0;i<=N+50;i++){
        for(int j=0;j<edges.size();j++){
            int start= get<0>(edges[j]);
            int end = get<1>(edges[j]);
            int price = get<2>(edges[j]);

            // 시작점에 도달한 적이 없으면 무시
            // (출발점에서 갈 수 없는 경로는 의미 없음)
            if(D[start]==LONG_MIN){
                continue;
            }
            // 이미 무한 이익 상태라면
            // 그 다음 도시도 무한 이익으로 전파
            else if(D[start]==LONG_MAX){
                D[end]=LONG_MAX;
            }
            // 더 큰 이익으로 갱신 가능한 경우
            else if(D[end]<D[start]+earn[end]-price){
                D[end]=D[start]+earn[end]-price;

                // N번째 이후에도 갱신된다면
                // 양의 사이클의 영향을 받는 것으로 판단
                if(i>=N-1){
                    D[end]=LONG_MAX;
                }
            }
        }
    }

    // 결과 판정
    if(D[E]==LONG_MIN){
        // 도착 도시까지 갈 수 없는 경우
        cout<<"gg"<<"\n";
    }else if(D[E]==LONG_MAX){
        // 무한히 돈을 벌 수 있는 경우
        cout<<"Gee"<<"\n";
    }else{
        // 유한한 최대 이익
        cout<<D[E]<<"\n";
    }
}
