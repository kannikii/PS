#include <iostream>
#include <stack>
#include <vector>

// 스택 top이 X라면 → pop
// 아니라면 → X가 나올 때까지 push
// push를 다 했는데도 top이 X가 아니면 → 불가능
using namespace std;

stack<int> myStack;
int main() {
    int N;
    cin >> N;
    vector<int> A(N, 0);
    vector<char> resultV;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int nextPush = 1;
    for (int i = 0; i < N; i++) {
        int X = A[i];

        while (nextPush <= X) {
            myStack.push(nextPush);
            resultV.push_back('+');
            nextPush++;
        }

        if (!myStack.empty() && myStack.top() == X) {
            myStack.pop();
            resultV.push_back('-');
        } else {
            cout << "NO";
            return 0;
        }
    }
    for (char c : resultV) {
        cout << c << '\n';
    }
}