#include <iostream>
#include <stack>
using namespace std;

int N;
string command[10000];
int value[10000];

int main() {
    cin >> N;
    stack<int> s;
    for (int i = 0; i < N; i++) {
        cin >> command[i];
        if (command[i] == "push") {
            cin >> value[i];
            s.push(value[i]);
        }else if(command[i]=="pop"){
            int e=s.top();
            s.pop();
            cout<<e<<"\n";
        }else if(command[i]=="size"){
            cout<<s.size()<<"\n";
        }else if(command[i]=="empty"){
            if(s.empty()){
                cout<<"1"<<"\n";
            }else{
                cout<<"0"<<"\n";
            }
        }else if(command[i]=="top"){
            cout<<s.top()<<"\n";
        }
    }

    return 0;
}
