#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
static long A[10000001];
int main(){
    long N;
    cin>>N;

    for(int i=2;i<10000001;i++){
        A[i]=i;
    }
    for(int i=2;i<=sqrt(10000001);i++){
        if(A[i]==0) continue;
        for(int j=i+i;j<10000001;j+=i){
            A[j]=0;
        }
    }

    for(int i=N;i<10000001;i++){
        if(A[i]!=0){
            // N보다 큰 소수들 중에서 팰린드롬 찾기
            string pd;
            pd=to_string(A[i]);
            int S,E;
            S=0;
            E=pd.size()-1;
            while(S<=E){
                if(pd[S]!=pd[E]){
                    A[i]=0;
                    break;
                }
                S++;
                E--;
            }

        }
    }

    for(int i=N;i<10000001;i++){
        if(A[i]!=0){
            cout<<A[i]<<"\n";
            break;
        }
    }
}