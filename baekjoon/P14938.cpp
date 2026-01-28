#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;
static vector<vector<pair<int, int>>> adj;
static int N, M, R;
static vector<int> items;
vector<int> dijkstra(int start);
int main() {
    cin >> N >> M >> R;
    items.resize(N+1);
    adj.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> items[i];
    }

    for (int i = 0; i < R; i++) {
        int A, B, L;
        cin >> A >> B >> L;
        adj[A].push_back({L, B});
        adj[B].push_back({L, A});
    }

    // 출발지가 정해지지 않은 문제, 모든 경로에 대해 가능한 최대 아이템 개수를 구하고 출력 -> 플로이드-워셀 
    // 다익스트라로 하면 모든 정점을 출발지로 N번 다익스트라 수행
    // 이후 각 노드별 결과 dist배열에서 최댓값 갱신 후 출력
    int answer=-1;
    for(int i=1;i<=N;i++){
        vector<int> dist = dijkstra(i);
        int sum=0;
        for(int j=1;j<dist.size();j++){
            
            if(dist[j]<=M){
                sum+=items[j];
            }
        }
        answer=max(answer,sum);
    }
    cout<<answer<<"\n";
}
vector<int> dijkstra(int start){
    vector<int> dist(N+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;

    dist[start]=0;
    pq.push({0,start});

    while(!pq.empty()){
        auto [nowCost,nowNode]=pq.top();
        pq.pop();
        if(nowCost>dist[nowNode])continue;

        for(auto[nextCost,nextNode]:adj[nowNode]){
            if(dist[nextNode]>dist[nowNode]+nextCost){
                dist[nextNode]=dist[nowNode]+nextCost;
                pq.push({dist[nextNode],nextNode});
            }
        }
    }
    return dist;
}