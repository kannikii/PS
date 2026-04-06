#include <iostream>
#include <string>

using namespace std;

int main() {
    int len;
    int sum = 0;
    string name;
    cin >> len >> name;
    
    for(int i = 0; i < len; i++) {
        int tmp = name[i]-'A'+1;
        sum += tmp;
    }
    
    cout << sum;
}
