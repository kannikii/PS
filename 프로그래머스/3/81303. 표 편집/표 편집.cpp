#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {

    vector<int> prev(n), next(n);

    for (int i = 0; i < n; i++) {
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    next[n - 1] = -1;

    stack<pair<int, pair<int, int>>> removed;
    // {현재행, {이전행, 다음행}}

    int cur = k;

    for (string s : cmd) {

        if (s[0] == 'U') {
            int x = stoi(s.substr(2));
            while (x--) cur = prev[cur];
        }

        else if (s[0] == 'D') {
            int x = stoi(s.substr(2));
            while (x--) cur = next[cur];
        }

        else if (s[0] == 'C') {

            removed.push({cur, {prev[cur], next[cur]}});

            if (prev[cur] != -1)
                next[prev[cur]] = next[cur];

            if (next[cur] != -1)
                prev[next[cur]] = prev[cur];

            if (next[cur] != -1)
                cur = next[cur];
            else
                cur = prev[cur];
        }

        else { // Z

            int now = removed.top().first;
            int p = removed.top().second.first;
            int n = removed.top().second.second;
            removed.pop();

            if (p != -1)
                next[p] = now;

            if (n != -1)
                prev[n] = now;
        }
    }

    string answer(n, 'O');

    while (!removed.empty()) {
        answer[removed.top().first] = 'X';
        removed.pop();
    }

    return answer;
}