#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

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

static int N;
static int cnt = 0;
static vector<int> A(15,0);
void backtracking(int row);
bool check(int row);
int main() {
    cin >> N;
    backtracking(0);
    cout << cnt << "\n";
}

void backtracking(int row) {
    if (row == N) {
        cnt++;
        return;
    }
    for (int i = 0; i < N; i++) {
        A[row] =i;
        if(check(row)){
            backtracking(row+1);
        }
    }
}

bool check(int row){
    for(int i=0;i<row;i++){
        if(A[i]==A[row]){   //같은 열 검사
            return false;
        }
        if(abs(row-i)==abs(A[i]-A[row])){   //대각선 검사
            return false;
        }
    }
    return true;
}
