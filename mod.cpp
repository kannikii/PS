#include <iostream>
using namespace std;

int main() {
    long long answer = 1;
    for(int i=1; i<=50;i++){
        //answer=(answer*i);
        answer=(answer*i)%10007;
    }
    //answer%10007 -> overflow로 음수 나옴 
    //나머지에 대한 곱셈의 분배법칙 활용
    cout << answer;
}