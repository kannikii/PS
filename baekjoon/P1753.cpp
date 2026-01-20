#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// 다익스트라(dijkstra) 알고리즘 
// 1. 인접 리스트
// 2. 최단 거리 배열 초기화 (출발노드:0, 나머지:무한)
// 3. 값이 가장 작은 노드 고르기
// 4. 최단 거리 배열 갱신 (3번에서 선택한 노드의 연결된 노드의 가중치 값으로 갱신)
// 5. 최단 거리 배열 갱신 반복 (더 작은 값으로 계속 갱신) 및 완성
typedef pair<int,int> edge;
static vector<int> D;
static vector<bool> visited;
static vector<vector<edge>> A;
static priority_queue<edge,vector<edge>,greater<edge>> myQueue;
int main() {
    int V,E;
    cin>> V>>E;
    int K;
    cin>>K;
    // 1. 인접 리스트
    A.resize(V+1);
    for(int i=1;i<=E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        A[u].push_back({w,v});
    }
    // 2. 최단 거리 배열 초기화
    D.resize(V+1);
    fill(D.begin(),D.end(),INT_MAX);
    visited.resize(V+1);
    fill(visited.begin(),visited.end(),false);

    D[K]=0;
    myQueue.push({0,K}); // 다익스트라 표준은 (현재까지 거리, 정점)

    while(!myQueue.empty()){
        edge now = myQueue.top();
        myQueue.pop();
        int curNode=now.second;
        int curDist=now.first;
        if(visited[curNode]) continue;  // 이미 방문한 노드는 다시 큐에 넣지 않음
        visited[curNode]=true;
        // if(curDist > D[curNode] continue;
        // 지금나오려는 가중치 > 원래최단거리로 계산되었던 가중치
        // 더 안좋은 길이므로 무시 continue;
        // 이 코드 한줄로 visited[] 생략 가능
        for(edge next: A[curNode]){
            int nextNode=next.second;
            int nextValue=next.first;

            if(D[nextNode]>D[curNode]+nextValue){
                D[nextNode]=D[curNode]+nextValue;
                myQueue.push({D[nextNode],nextNode});
            }
        }
    }

    // 5. 완성된 거리 배열 출력
    for(int i=1;i<=V;i++){
        if (D[i] == INT_MAX) cout << "INF\n";
        else cout << D[i] << "\n";
    }
}