#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;

typedef tuple<int, int, int> edge;
static vector<edge> edges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        edges.clear();

        int N, M;
        cin >> N >> M;

        vector<vector<int>> revAdj(N); // [추가] 역방향 그래프

        for (int j = 0; j < M; j++) {
            int A, B, C;
            cin >> A >> B >> C;
            edges.push_back({A, B, C});
            revAdj[B].push_back(A); // [추가] B -> A (원래는 A -> B)
        }

        // [추가] canReach0[x] = x에서 0으로 돌아갈 수 있으면 1
        vector<int> canReach0(N, 0);
        queue<int> q;
        q.push(0);
        canReach0[0] = 1;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int prev : revAdj[cur]) {
                if (!canReach0[prev]) {
                    canReach0[prev] = 1;
                    q.push(prev);
                }
            }
        }

        const long long INF = (1LL << 60);
        vector<long long> D(N, INF);
        D[0] = 0;

        // Bellman-Ford: N-1번 완화
        for (int k = 0; k < N - 1; k++) {
            bool updated = false;
            for (int l = 0; l < (int)edges.size(); l++) {
                int start = get<0>(edges[l]);
                int end   = get<1>(edges[l]);
                int cost  = get<2>(edges[l]);

                if (D[start] != INF && D[end] > D[start] + cost) {
                    D[end] = D[start] + cost;
                    updated = true;
                }
            }
            if (!updated) break;
        }

        bool possible = false;

        // 한 번 더 완화가 가능한가? + (중요) 그 end가 0으로 돌아올 수 있는가?
        for (int l = 0; l < (int)edges.size(); l++) {
            int start = get<0>(edges[l]);
            int end   = get<1>(edges[l]);
            int cost  = get<2>(edges[l]);

            if (D[start] != INF && D[end] > D[start] + cost && canReach0[end]) {
                possible = true;
                break;
            }
        }

        if (!possible) {
            cout << "Case #" << tc << ": not possible\n";
        } else {
            cout << "Case #" << tc << ": possible\n";
        }
    }
}


// #include <iostream>
// #include <tuple>
// #include <vector>
// #include <climits>
// using namespace std;

// typedef tuple<int, int, int> edge;
// static vector<edge> edges;

// int main() {
//     int T;
//     cin >> T;
//     for (int i = 0; i < T; i++) {
//         edges.clear();

//         int N, M;
//         cin >> N >> M;
//         // 0~N-1번까지 노드
//         for (int j = 0; j < M; j++) {
//             int A, B, C;
//             cin >> A >> B >> C;
//             edges.push_back({A, B, C});
//         }
//         vector<long> D(N, LONG_MAX);
//         D[0] = 0;
//         for (int k = 0; k < N - 1; k++) {
//             for (int l = 0; l < edges.size(); l++) {
//                 int start = get<0>(edges[l]);
//                 int end = get<1>(edges[l]);
//                 int cost = get<2>(edges[l]);

//                 if (D[start] != LONG_MAX && D[end] > D[start] + cost) {
//                     D[end] = D[start] + cost;
//                 }
//             }
//         }
//         bool mCycle = false;

//         for (int l = 0; l < edges.size(); l++) {
//             int start = get<0>(edges[l]);
//             int end = get<1>(edges[l]);
//             int cost = get<2>(edges[l]);

//             if (D[start] != LONG_MAX && D[end] > D[start] + cost) {
//                 mCycle=true;
//             }
//         }

//         if(!mCycle){
//             cout<<"Case #"<<i+1<<": not possible"<<"\n";
//         }else{
//             cout<<"Case #"<<i+1<<": possible"<<"\n";
//         }
//     }
// }