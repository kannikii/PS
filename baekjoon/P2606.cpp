#include <iostream>
#include <queue>
#include <vector>

using namespace std;

static int N,K;
static int result=0;
static vector<vector<int>> A;
static queue<int> myQueue;
static vector<bool> visited;
void BFS(int node);

int main() {
    cin>>N>>K;
    A.resize(N+1);
    visited=vector<bool>(N+1,false);
    for(int i=0;i<K;i++){
        int s,e;
        cin>>s>>e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    BFS(1);
    cout<<result<<"\n";
}
void BFS(int node){
    visited[node]=true;
    myQueue.push(node);

    while(!myQueue.empty()){
        int nowNode=myQueue.front();
        myQueue.pop();
        for(int i: A[nowNode]){
            if(!visited[i]){
                myQueue.push(i);
                visited[i]=true;
                result++;
            }
        }

    }
}

