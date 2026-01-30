#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
static vector<int> parent;
typedef struct Edge{
    int s,e;
    float v;
    bool operator > (const Edge& temp) const {
        return v > temp.v;
    }
}Edge;
static priority_queue<Edge,vector<Edge>,greater<Edge>> pq;
void unionfunc(int a,int b);
int find(int a);
int main() {
    int N;
    cin>>N;
    vector<pair<float,float>> stars;
    stars.push_back({0,0});
    parent.resize(N+1);
    for(int i=0;i<=N;i++){
        parent[i]=i;
    }
    for(int i=1;i<=N;i++){
        float x,y;
        cin>>x>>y;
        stars.push_back({x,y});
    }

    // 모든 별끼리의 가능한 거리 계산 및 
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            float a_x=stars[i].first;
            float a_y=stars[i].second;

            float b_x=stars[j].first;
            float b_y=stars[j].second;
            float distance = sqrt(pow((a_x-b_x),2)+pow((a_y-b_y),2));
            pq.push({i,j,distance});
        }
    }

    int useEdge=0;
    float result=0;
    while(!pq.empty()&&useEdge<N-1){
        Edge now = pq.top();
        pq.pop();
        if(find(now.s)!=find(now.e)){
            unionfunc(now.s,now.e);
            useEdge++;
            result+=now.v;
        }
    }
    cout<<result<<"\n";
}
void unionfunc(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        parent[b]=a;
    }
}
int find(int a){
    if(a==parent[a]){
        return a;
    }else{
        return parent[a]=find(parent[a]);
    }
}