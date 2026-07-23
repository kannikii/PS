#include <iostream>
#include <stack>
using namespace std;

int main() {
    // Please write your code here.
    string line;
    cin>>line;
    stack<char> s;
    bool valid =true;
    for(int i=0;i<line.length();i++){
        if(line[i]=='('){
            s.push('(');
        }else if(!s.empty()&&line[i]==')'){
            s.pop();
        }else{
            valid=false;
            break;
        }
    }
    if(!s.empty()) valid=false;
    valid ? cout << "Yes" : cout << "No";
    return 0;
}