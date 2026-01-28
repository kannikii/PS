#include <iostream>
#include <climits>

using namespace std;

int main() {
    int V,E;
    cin>>V>>E;
    long D[401][401];
    for(int i=0;i<=V;i++){
        for(int j=0;j<=V;j++){
            if(i==j)D[i][j]=0;
            else D[i][j]=INT_MAX;
        }
    }
    
    for(int i=0;i<E;i++){
        int A,B,C;
        cin>>A>>B>>C;
        D[A][B]=C;
    }

    for(int k=1;k<=V;k++){
        for(int i=1;i<=V;i++){
            for(int j=1;j<=V;j++){
                if(D[i][k]!=INT_MAX&&D[k][j]!=INT_MAX){
                    D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
                }
            }
        }
    }
    // // 출발점과 도착점이 같은 경우에서의 최소의 길이 찾기
    
    // 사이클은 D[i][i]에 있다
    long Min=INT_MAX;
    for (int i = 1; i <= V; i++) {
        if (D[i][i] > 0) {
            Min = min((int)Min, (int)D[i][i]);
        }
    }
    // for(int i=1;i<=V;i++){
    //     int cycle=INT_MAX;
    //     for(int j=1;j<=V;j++){
    //         if(i!=j){
    //             if(D[i][j]!=INT_MAX&&D[j][i]!=INT_MAX){
    //                 cycle=min(cycle,(int)D[i][j]+(int)D[j][i]);
    //             }
    //         }else{
    //             if(D[i][j]==0) continue;
    //         }
    //     }
    //     Min=min(Min,cycle);
    // }
    if(Min==INT_MAX){
        cout<<-1<<"\n";
    }else{
        cout<<Min<<"\n";
    }
}

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    const long INF = 1e9;
    long D[401][401];
    vector<pair<pair<int,int>, long>> edges; // 간선 저장
    
    // 초기화
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (i == j) D[i][j] = 0;
            else D[i][j] = INF;
        }
    }
    
    // 간선 입력
    for (int i = 0; i < E; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        D[A][B] = C;
        edges.push_back({{A, B}, C});
    }
    
    // 플로이드-워셜
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (D[i][k] != INF && D[k][j] != INF) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
    }
    
    long answer = INF;
    
    // 각 간선 (A→B)에 대해 B→A 경로 확인
    for (auto& edge : edges) {
        int A = edge.first.first;
        int B = edge.first.second;
        long cost = edge.second;
        
        if (D[B][A] != INF) {
            answer = min(answer, D[B][A] + cost);
        }
    }
    
    if (answer == INF) cout << -1 << "\n";
    else cout << answer << "\n";
}