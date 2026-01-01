#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct compare{
    bool operator()(int o1, int o2){
        int first_abs=abs(o1);
        int second_abs=abs(o2);
        if(first_abs==second_abs){
            return o1>o2;   //절대값 같을때 음수 우선 정렬
        }else{
            return first_abs>second_abs; //절대값 기준으로 정렬
        }
    }
};
//우선순위 큐 (정렬 조건 사용자 정의)
int main() {
    int N;
    cin>>N;

    priority_queue<int,vector<int>,compare> pq;

    for(int i=0;i<N;i++){
        int request;
        cin>>request;

        if(request==0){
            if(pq.empty()){
                cout<<"0"<<"\n";
            }
            else {
                cout <<pq.top() <<"\n";
                pq.pop();
            }
        }else{
            pq.push(request);
        }
    }

}