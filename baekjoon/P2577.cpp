#include <iostream>
#include <string>
using namespace std;

int main() {
    int A,B,C;
    cin>>A>>B>>C;

    string num;
    num=to_string(A*B*C);

    int cnt[10]={};
    for(char ch: num){
        cnt[ch-'0']++;
    }
    for (int i = 0; i < 10; i++) {
        cout << cnt[i] << '\n';
    }
}

