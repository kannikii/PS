
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int grid[100][100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    int answer = 0;

    for (int i = 0; i < n; i++) {
        int r = 1, c = 1, rbest = 1, cbest = 1;
        for (int j = 1; j < n; j++) {
            r = (grid[i][j] == grid[i][j - 1]) ? r + 1 : 1;   // i번째 행
            c = (grid[j][i] == grid[j - 1][i]) ? c + 1 : 1;   // i번째 열
            rbest = max(rbest, r);
            cbest = max(cbest, c);
        }
        if (rbest >= m) answer++;
        if (cbest >= m) answer++;
    }

    cout << answer;
    return 0;
}