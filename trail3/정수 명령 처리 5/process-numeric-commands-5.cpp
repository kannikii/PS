#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;

    while(n--){
        string cmd;
        cin >> cmd;

        if(cmd == "push_back"){
            int x;
            cin >> x;
            v.push_back(x);
        }
        else if(cmd == "pop_back"){
            v.pop_back();
        }
        else if(cmd == "size"){
            cout << v.size() << '\n';
        }
        else if(cmd == "get"){
            int k;
            cin >> k;
            cout << v[k-1] << '\n';
        }
    }

    return 0;
}