#include <iostream>
#include <queue>
#include <vector>

using namespace std;
priority_queue<int,vector<int>, greater<int>> pq;


//우선순위 큐 (정렬 조건 사용자 정의)(min-heap)
int main() {
    int N,M,K;
    cin>>N>>M>>K;
    
    vector<int> pTime(N,0);

    //100,200
    for(int i=0;i<N;i++){
        cin>>pTime[i]; 
    }
    for(int i=0;i<M;i++){
        pq.push(pTime[i]);
    }

    int i=M;
    //반복해야할것들 pTime[i]다 꺼내서 push하면 종료
    while(i<N){
        int x=pq.top();
        pq.pop();
        pq.push(x+pTime[i]);
        i++;
    }
    
    //종료된 min히프에서 최소값 찾기 -> top
    if(pq.top()>K){
        cout<<"GO"<<"\n";
    }else{
        cout<<"WAIT"<<"\n";
    }

}