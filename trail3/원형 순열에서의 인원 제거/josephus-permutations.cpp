#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // Please write your code here.
    int N,K;
    cin>>N>>K;
    vector<int> answer;
    queue<int> q;

    for(int i=1;i<=N;i++){
        q.push(i);
    }
    while(!q.empty()){
        for(int i=0;i<K-1;i++){
            q.push(q.front());
            q.pop();
        }
        answer.push_back(q.front());
        q.pop();
    }

    for(auto it:answer){
        cout<<it<<" ";
    }

    return 0;
}