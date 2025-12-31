#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N,M;
    cin>>N>>M;

    vector<int> v(N,0);
    for(int i=0;i<N;i++){
        cin>>v[i];

    }
    sort(v.begin(),v.end());

    //nC3의 경우의 수 
    int sum=0;
    int answer=0;
    for(int i=0;i<N;i++){

        for(int j=i+1;j<N;j++){

            for(int k=j+1;k<N;k++){
                sum=v[i]+v[j]+v[k];
                if(sum<=M&&sum>answer){
                    //sum중에서 제일 큰수가 정답 갱신-> 출력
                    answer=sum;

                }
            }
        }
    }

    cout<<answer<<"\n";
}