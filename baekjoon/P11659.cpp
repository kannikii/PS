#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin>>N>>M;
    int S[100001]={};
    for(int i=1;i<=N;i++){
        int tmp;
        cin>>tmp;
        S[i]=S[i-1]+tmp;
    }
    int k,l;
    for(int j=1;j<=M;j++){
        cin>>k>>l;
        cout<<S[l]-S[k-1]<<'\n';
    }
}