#include <iostream>
#include <map>
#include <string>

using namespace std;
// union-find는 숫자로만 하는데, 입력은 문자열이므로 이를 숫자로 바꿔야한다.
// 따라서 map을 사용하여 이름별로 번호를 부여한다.
static map<string,int> id;
static int parent[200001];
static int sz[200001];
void unionfunc(int a, int b);
int find(int a);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int F;
        cin>>F;
        
        id.clear();     // 테스트 케이스 한 번마다 초기화
        int nextId=1;   // 사람 하나 추가될 때마다 번호 +1

        for(int j=1;j<=F;j++){
            string friendA,friendB;
            cin>>friendA>>friendB;

            // map에 없는 이름이면 -> 새번호
            // map에 있는 이름이면 -> 기존번호
            // 번호 각각 가져와서 이들을 union()
            // union() 이후 size 크기 출력
            if(id.count(friendA)==0){
                id[friendA]=nextId;
                parent[nextId]=nextId;
                sz[nextId]=1;
                nextId++;
            }
            if(id.count(friendB)==0){
                id[friendB]=nextId;
                parent[nextId]=nextId;
                sz[nextId]=1;
                nextId++;
            }

            unionfunc(id[friendA],id[friendB]);
            int root=find(id[friendA]);
            cout<<sz[root]<<"\n";
        }
    }
}
void unionfunc(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        parent[b]=a;
        sz[a]+=sz[b];
    }
}
int find(int a){
    if(a==parent[a]){
        return a;
    }else{
        return parent[a]=find(parent[a]);
    }
}