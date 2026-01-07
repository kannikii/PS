#include <iostream>
#include <vector>
using namespace std;
static int N, M;
static vector<int> S;
static vector<bool> V(8,false);
void backtracking(int length);
int main() {
    cin >> N >> M;
    
    backtracking(0);
}

void backtracking(int length){
    if(length==M){
        for(int x:S){
            cout<<x<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=N;i++){
        if(V[i]==false){
            V[i]=true;
            S.push_back(i);
            backtracking(length+1);
            S.pop_back();
            V[i]=false;
        }
    }
}
// 백트래킹 문제 기본 틀
// void backtracking(상태) {
//     if (완성 조건) {
//         출력;
//         return;
//     }

//     for (선택지들) {
//         if (불가능한 선택) continue;

//         선택한다;
//         backtracking(다음 상태);
//         선택을 되돌린다;
//     }
// }
