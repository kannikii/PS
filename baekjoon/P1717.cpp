#include <iostream>
#include <vector>
using namespace std;
static vector<int> parent;
void unionfunc(int a, int b);
bool checkSame(int a, int b);
int find(int a);
// 유니온-파인드 연산 그래프 탐색에 사용
int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    parent.resize(n+1);    
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }

    for(int i=0;i<m;i++){
        int cmd,a,b;
        cin>>cmd>>a>>b;
        if(cmd==0){
            unionfunc(a,b);
        }else if(cmd==1){
            if(checkSame(a,b)){
                cout<<"YES"<<"\n";
            }else{
                cout<<"NO"<<"\n";
            }
        }
    }
}
// union 연산: 바로 연결이 아닌 대표 노드끼리 연결함
void unionfunc(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        parent[b]=a;
    }
}
// 대표 노드 찾아서 반환
int find(int a){
    if(a==parent[a]){
        return a;
    }else{
        return parent[a]=find(parent[a]);
    }
}
// 두 원소가 같은 집합인지 확인
bool checkSame(int a, int b){
    a=find(a);
    b=find(b);
    if(a==b){
        return true;
    }else{
        return false;
    }
}