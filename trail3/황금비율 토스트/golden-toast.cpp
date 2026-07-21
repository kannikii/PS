#include <iostream>
#include <string>
#include <list>

using namespace std;

int n, m;
string s;

int main() {
    cin >> n >> m;
    cin >> s;
    list<char> l;
    for(auto p:s){
        l.push_back(p);
    }
    
    list<char>::iterator it;
    it=l.end();
    for (int i = 0; i < m; i++) {
        char command;
        cin >> command;
        if (command == 'P') {
            char c;
            cin >> c;
            it=l.insert(it,c);
            it++;
        }else if(command=='L'){
            if(it!=l.begin()){
                it--;
            }
        }else if(command=='R'){
            if(it!=l.end()){
                it++;
            }
        }else if(command=='D'){
            if(it!=l.end()){
                it=l.erase(it);
            }
        }

    }
    for(it=l.begin();it!=l.end();it++){
        cout<<*it;
    }
    
    return 0;
}
