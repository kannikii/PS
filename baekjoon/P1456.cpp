#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long M,N;
    cin>>M>>N;

    long A[10000001];

    for(int i=2;i<10000001;i++){
        A[i]=i;
    }
    for(int i=2;i<=sqrt(10000001);i++){
        if(A[i]==0) continue;
        for(int j=i+i;j<10000001;j+=i){
            A[j]=0;
        }
    }
    
    int cnt=0;
    for(int i=2;i<10000001;i++){
        if(A[i]!=0){
            long temp = A[i];
            while((double)A[i]<=(double)N/(double)temp){
                if((double)A[i]>=(double)M/(double)temp){
                    cnt++;
                }
                temp=temp*A[i];
            }
        }
    }
    cout<<cnt<<"\n";
}