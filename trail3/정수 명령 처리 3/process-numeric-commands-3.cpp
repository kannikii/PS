#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> q;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "push_back") {
            int num;
            cin >> num;
            q.push_back(num);
        }
        else if (cmd == "push_front") {
            int num;
            cin >> num;
            q.push_front(num);
        }
        else if (cmd == "pop_front") {
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop_front();
            }
        }
        else if (cmd == "pop_back") {
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.back() << '\n';
                q.pop_back();
            }
        }
        else if (cmd == "size") {
            cout << q.size() << '\n';
        }
        else if (cmd == "empty") {
            cout << (q.empty() ? 1 : 0) << '\n';
        }
        else if (cmd == "front") {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else if (cmd == "back") {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }

    return 0;
}
