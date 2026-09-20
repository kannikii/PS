#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int A[100], B[100];

int main() {
    cin >> N >> K;
    vector<int> v(N+1,0);

    for (int i = 0; i < K; i++) {
        cin >> A[i] >> B[i];
        for(int j=A[i];j<=B[i];j++){
            v[j]++;
        }
    }

    // Please write your code here.
    cout<< *max_element(v.begin()+1,v.end());

    return 0;
}