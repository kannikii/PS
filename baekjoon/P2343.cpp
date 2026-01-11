#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N,M;
    cin>>N>>M;
    vector<int> A(N);
    
    int sum=0;
    
    for(int i=0;i<N;i++){
        cin>>A[i];
        sum+=A[i];
    }
    
    int left,right;

    left=*max_element(A.begin(),A.end());
    right=sum;

    while(left<=right){
        // 9~45까지 이분탐색
        // mid 갱신해가며 개수가 3이하이면 계속 탐색
        // 3이상이면 불가능 -> 다시탐색
        int mid=(left+right)/2;

        int cur=0;
        int cnt=1;

        for(int i=0;i<N;i++){
            if(cur+A[i]<=mid){
                cur+=A[i];
            }else{
                cnt++;
                cur=A[i];
            }
        }
        if(cnt<=M){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }

    cout<<left<<"\n";
}