#include <iostream>
#include <vector>

using namespace std;
static int cnt = 0;
static vector<int> trueP;
static int partyP[51][51];
static int partySize[51];
static vector<int> parent;

void unionfunc(int a, int b);
int find(int a);

int main() {
    int N, M, T;
    cin >> N >> M;
    
    
    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    
    cin >> T;
    trueP.resize(T);
    if (T != 0) {
        for (int i = 0; i < T; i++) {
            cin >> trueP[i];
        }
    }
    
    // 진실을 아는 사람들끼리 union
    if (T > 1) {
        for (int i = 1; i < T; i++) {
            unionfunc(trueP[0], trueP[i]);
        }
    }

    // 파티 정보 입력
    for (int i = 0; i < M; i++) {
        cin >> partySize[i];
        for (int j = 1; j <= partySize[i]; j++) {
            cin >> partyP[i][j];
        }
    }

    // 각 파티의 참석자들끼리 union
    for (int i = 0; i < M; i++) {
        int firstP = partyP[i][1];  
        for (int j = 2; j <= partySize[i]; j++) {  
            unionfunc(firstP, partyP[i][j]);
        }
    }

    // 정답 판별
    for (int i = 0; i < M; i++) {
        bool canLie = true;

        for (int j = 1; j <= partySize[i]; j++) {  
            int person = partyP[i][j];

            if (T > 0 && find(person) == find(trueP[0])) {
                canLie = false;
                break;
            }
        }

        if (canLie) cnt++;
    }

    cout << cnt << "\n";
    return 0;
}

void unionfunc(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}

int find(int a) {
    if (a == parent[a]) {
        return a;
    } else {
        return parent[a] = find(parent[a]);
    }
}