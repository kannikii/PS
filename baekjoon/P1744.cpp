#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    priority_queue<int> positiveQ;
    priority_queue<int, vector<int>, greater<int>> negativeQ;
    int one = 0;
    int zero = 0;
    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        if (data > 0) {
            if (data == 1) {
                one++;
            } else {
                positiveQ.push(data);
            }
        } else if (data == 0) {
            zero++;
        } else if (data < 0) {
            negativeQ.push(data);
        }
    }
    int result = 0;
    while (positiveQ.size() > 1) {
        int data1;
        int data2;
        data1 = positiveQ.top();
        positiveQ.pop();
        data2 = positiveQ.top();
        positiveQ.pop();

        result += data1 * data2;
    }
    if (positiveQ.size() != 0) {
        result += positiveQ.top();
        positiveQ.pop();
    }

    while (negativeQ.size() > 1) {
        int data1;
        int data2;
        data1 = negativeQ.top();
        negativeQ.pop();
        data2 = negativeQ.top();
        negativeQ.pop();

        result += data1 * data2;
    }
    if (negativeQ.size() != 0) {
        if (zero == 0) {
            result += negativeQ.top();
            negativeQ.pop();
        }
    }
    result+=one;
    cout<<result<<"\n";
}