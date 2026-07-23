#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Please write your code here.
    queue<int> q;
    int N;
    cin>>N;

    for(int i=0; i<N;i++){
        string cmd;
        cin>>cmd;
        if(cmd=="push"){
            int num;
            cin>>num;
            q.push(num);
        }else if(cmd=="pop"){
            cout<<q.front()<<"\n";
            q.pop();
        }else if(cmd=="size"){
            cout<<q.size()<<"\n";
        }else if(cmd=="empty"){
            q.empty()?cout<<"1"<<"\n":cout<<"0"<<"\n";
        }else if(cmd=="front"){
            cout<<q.front()<<"\n";
        }else{
            break;
        }
    }
    return 0;
}