#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    // int N, K;
    // cin >> N >> K;
    // vector<int> A(N, 0);
    // for (int i = 0; i < N; i++) {
    //     cin >> A[i];
    // }

    // sort(A.begin(), A.end());

    // cout << A[K - 1] << "\n";

    // 퀵정렬
    int N, K;
    cin >> N >> K;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }


}

// void quickSort(vector<int> &A, int S, int E, int K){
//     int pivot = partition(A,S,E);
//     if(pivot==K){
//         return ;
//     }
// }

