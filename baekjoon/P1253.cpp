#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> A(N,0);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end());

    int result =0;
    for(int i=0;i<N;i++){
        long M=A[i];
        int j=0;
        int k=N-1;

        while(j<k){
           if(A[j]+A[k]==M){
            if(j!=i&&k!=i){
                result++;
                break;
            }else if(j==i){
                j++;
            }else if(k==i){
                k--;
            }
           }
           else if(A[j]+A[k]<M){
            j++;
           }else{
            k--;
           }
        }
    }
    cout<<result<<"\n";
}