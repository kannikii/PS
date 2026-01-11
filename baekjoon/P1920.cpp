#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N, 0);
    int M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> M;
    vector<int> target(M, 0);
    for (int i = 0; i < M; i++) {
        cin >> target[i];
    }
    vector<int> result(M, 0);

    sort(A.begin(), A.end());

    for (int i = 0; i < M; i++) {
        int left = 0;
        int right = N - 1;
        
        while (left<=right) {
            int mid = (left + right) / 2;
            if (A[mid] == target[i]) {
                result[i]=1;
                break;
            }else if(A[mid]>target[i]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
    }

    for (int i : result) {
        cout << i << "\n";
    }
}