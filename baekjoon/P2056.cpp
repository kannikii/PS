#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
static vector<vector<int>> adj_list;
static vector<int> jobtime;
static vector<int> D;
int main() {
    int N;
    cin>> N;
    jobtime.resize(N+1);
    adj_list.resize(N+1);
    for(int i=1;i<=N;i++){
        cin>>jobtime[i];   //i번 작업 하나에 걸리는 시간

        int pre;
        cin>> pre;
        if(pre!=0){
            for(int j=1;j<=pre;j++){
                int prejob;
                cin>>prejob;
                adj_list[prejob].push_back(i);
            }
        }
    }
    D.resize(N+1);
    for(int i=1;i<=N;i++){
        for(int j:adj_list[i]){
            D[j]++;
        }
    }

    queue<int> myQueue;
    vector<int> dist(N+1,0);
    for(int i=1;i<=N;i++){
        if(D[i]==0){
            myQueue.push(i);
            dist[i]=jobtime[i];
        }
    }

    while(!myQueue.empty()){
        int now=myQueue.front();
        myQueue.pop();

        for(int next: adj_list[now]){
            D[next]--;
            dist[next]=max(dist[next],dist[now]+jobtime[next]);
            if(D[next]==0){
                myQueue.push(next);
                
            }
        }
    }

    cout<<*max_element(dist.begin(), dist.end())<<"\n";
}