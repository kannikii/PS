#include <iostream>
#include <tuple>
#include <vector>
#include <climits>
using namespace std;

typedef tuple<int, int, int> edge;
static vector<edge> edges;
int main() {
    int TC;
    cin >> TC;
    for (int i = 0; i < TC; i++) {
        int N, M, W;
        cin >> N >> M >> W;
        edges.clear();
        for (int j = 0; j < M; j++) {
            int S, E, T;
            cin >> S >> E >> T;
            // 에지 리스트에 삽입
            edges.push_back({S, E, T});
            edges.push_back({E, S, T});
        }
        for (int k = 0; k < W; k++) {
            int S, E, T;
            cin >> S >> E >> T;
            // 에지 리스트에 T값 -1 곱해서 삽입
            edges.push_back({S, E, (-1) * T});
        }
        // 하나의 테스트 케이스에서 벨만-포드
        vector<int> D(N + 1, 0);
        

        for (int l = 1; l < N; l++) {
            for (int m = 0; m < edges.size(); m++) {    //양방향 간선이므로 M고정만큼 반복이아니라 edges요소만큼 반복
                edge medge = edges[m];
                int start = get<0>(medge);
                int end = get<1>(medge);
                int time = get<2>(medge);

                if (D[start] != INT_MAX && D[end] > D[start] + time) {
                    D[end] = D[start] + time;
                }
            }
        }
        bool mCycle = false;

        for (int n = 0; n < edges.size(); n++) {
            edge medge = edges[n];
            int start = get<0>(medge);
            int end = get<1>(medge);
            int time = get<2>(medge);

            if (D[start] != INT_MAX && D[end] > D[start] + time) {
                mCycle=true;
            }
        }
        if(!mCycle){
            cout<<"NO"<<"\n";
        }else{
            cout<<"YES"<<"\n";
        }
    }
}