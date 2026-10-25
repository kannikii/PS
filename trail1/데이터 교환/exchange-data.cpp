#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 6, c = 7;
    int temp = a;  // a의 원래 값 보관
    a = c;         // a에 c값 (7)
    c = b;         // c에 b값 (6)
    b = temp;      // b에 a의 원래 값 (5)
    cout << a << "\n" << b << "\n" << c;
    return 0;
}