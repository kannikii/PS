#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
typedef pair<int,int> edge;
static vector<vector<edge>> A;
static vector<int> D;

int main() {
    int N,M;
    cin>>N;
    cin>>M;
    A.resize(N+1);
    for(int i=1;i<=M;i++){
        int u,v,w;
        cin>>u>>v>>w;
        A[u].push_back({v,w});
    }
    int start_city,end_city;
    cin>>start_city>>end_city;
    
    D=vector<int>(N+1,INT_MAX);
    priority_queue <edge,vector<edge>,greater<edge>> myQueue;
    
    D[start_city]=0;
    myQueue.push({0,start_city});

    while(!myQueue.empty()){
        int curNode=myQueue.top().second;
        int curDist=myQueue.top().first;
        myQueue.pop();
        if(curDist>D[curNode])continue;
        for(edge next:A[curNode]){
            int nextNode=next.first;
            int nextDist=next.second;
            if(D[nextNode]>D[curNode]+nextDist){
                D[nextNode]=D[curNode]+nextDist;
                myQueue.push({D[nextNode],nextNode});
            }
        }
    }
    
    cout<<D[end_city]<<"\n";
}