#include <iostream>
#include <list>
using namespace std;
list<int> l;
int main() {
    // Please write your code here.
    int N;
    cin>>N;

    for(int i=0;i<N;i++){
        string input;
        cin>> input;
        int num;
        if(input=="push_back"){
            cin>>num;
            l.push_back(num);
        }else if(input=="push_front"){
            cin>>num;
            l.push_front(num);
        }else if(input=="pop_front"){
            cout<<l.front()<<"\n";
            l.pop_front();
        }else if(input=="pop_back"){
            cout<<l.back()<<"\n";
            l.pop_back();
        }else if(input=="front"){
            cout<<l.front()<<"\n";
        }else if(input=="back"){
            cout<<l.back()<<"\n";
        }else if(input=="size"){
            cout<<l.size()<<"\n";
        }else if(input=="empty"){
            if(l.empty()){
                cout<<1<<"\n";
            }else{
                cout<<0<<"\n";
            }
        }
    }
    return 0;
}