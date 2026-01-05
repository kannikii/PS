#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;


//우선순위 큐 (max-heap)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;

    priority_queue<int,vector<int>> pq;

    for(int i=0;i<N;i++){
        unsigned int request;
        cin>>request;

        if(request==0){
            if(pq.empty()){
                cout<<"0"<<"\n";
            }else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }else{
            pq.push(request);
        }
    }
}