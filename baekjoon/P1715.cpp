#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin>>N;
    priority_queue<int,vector<int>,greater<int>> pq;
    int card;
    for (int i = 0; i < N; i++) {
        cin>>card;
        pq.push(card);
    }
    int data1=0,data2=0;
    int sum=0;
    while(pq.size()!=1){
        data1=pq.top();
        pq.pop();
        data2=pq.top();
        pq.pop();
        sum+=data1+data2;
        pq.push(data1+data2);
    }
    cout<<sum<<"\n";
}