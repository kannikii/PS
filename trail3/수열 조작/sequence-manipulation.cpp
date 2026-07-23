#include <iostream>
#include <deque>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin>>N;
    deque<int> q;
    for(int i=1;i<=N;i++){
        q.push_back(i);
    }
    while(q.size()!=1){
        q.pop_front();
        
        q.push_back(q.front());
        q.pop_front();
    }

    cout<<q.front();
    return 0;
}