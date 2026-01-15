#include <iostream>
#include <vector>

using namespace std;
static vector<vector<int>> A;
static vector<bool> visited;
static bool isEven;
static vector<int> color; //색을 2로 나눈 나머지인 1,0으로만 구분
void DFS(int node);
int main() {
    int K;
    cin>>K;
    for(int i=0;i<K;i++){
        int V,E;
        cin>>V>>E;
        A.resize(V+1);
        visited.resize(V+1);
        color.resize(V+1);
        isEven=true;
        for(int i=0;i<E;i++){
            int u,v;
            cin>>u>>v;
            A[u].push_back(v);
            A[v].push_back(u); 
        }
        for(int i=1;i<=V;i++){
            if(isEven){
                DFS(i);
            }else{
                break;
            }
        }
        if(isEven){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
        //하나의 케이스 끝나고 초기화
        for(int i=0;i<=V;i++){
            A[i].clear();
            visited[i]=false;
            color[i]=0;
        }
    }
}

void DFS(int node){
    visited[node]=true;
    for(int i:A[node]){
        if(!visited[i]){
            color[i]=(color[node]+1)%2;
            DFS(i);
        }else if(color[i]==color[node]){
            isEven=false;
        }
    }
}