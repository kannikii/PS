#include <iostream>
#include <vector>
using namespace std;

int N, M;
int v[1000], t[1000];
int v2[1000], t2[1000];
vector<int> a(1000001,0);
vector<int> b(1000001,0);
int main() {
    cin >> N >> M;

    // a[1]=1, a[2]=2, a[3]=6, a[4]=7, a[5]=9, a[6]=11,...
    int timeA=1;
    for (int i = 0; i < N; i++) {
        cin >> v[i] >> t[i];

        for(int j=timeA;j<timeA+t[i];j++){
            a[j]=a[j-1]+v[i];
        }
        timeA=timeA+t[i];
    }

    // b[1]=2, b[2]=4, b[3]=6, b[4]=7, b[5]=8, b[6]=11, b[7]=14,...
    int timeB=1;
    for (int i = 0; i < M; i++) {
        cin >> v2[i] >> t2[i];

        for(int j=timeB;j<timeB+t2[i];j++){
            b[j]=b[j-1]+v2[i];
        }
        timeB=timeB+t2[i];
    }
    
    // 선두 바뀌는 횟수 검사
    char winner='C';
    int cnt=0;
    for(int i=1;i<b.size();i++){
        if(a[i]>b[i]){
            if(winner=='B'){
                winner='A';
                cnt++;
            }else{
                winner='A';
            }
        }else if(a[i]<b[i]){
            if(winner=='A'){
                winner='B';
                cnt++;
            }else{
                winner='B';
            }
        }

    }
    cout<<cnt;
    return 0;
}