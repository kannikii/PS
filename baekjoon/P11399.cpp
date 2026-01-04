#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin>>N;

    vector<int> A(N+1,0);
    for(int i=1;i<=N;i++){
        cin>>A[i];
    }

    sort(A.begin(),A.end());
    for(int i=1;i<=N;i++){
        A[i]+=A[i-1];
    }
    int sum=0;
    for(int i=1;i<=N;i++){
        sum+=A[i];
    }

    cout<<sum<<"\n";
}