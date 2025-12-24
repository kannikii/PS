#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//투 포인터 O(nlogn)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int M;
    cin>>N;
    cin>>M;
    vector<int> A(N,0);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    //정렬해도됨 N<=15000이므로 O(nlogn) 가능
    sort(A.begin(),A.end());

    int i=0;
    int j=N-1;
    int count=0;
    while(i<j){
        if(A[i]+A[j]<M){
            i++;
        }else if(A[i]+A[j]>M){
            j--;
        }else{
            count++;
            i++;
            j--;
        }
    }
    cout<<count<<"\n";
}