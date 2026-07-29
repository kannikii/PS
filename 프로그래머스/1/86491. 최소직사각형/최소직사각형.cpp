#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxW = 0;
    int maxH = 0;

    for (int i = 0; i < sizes.size(); i++) {
        // 항상 큰 값을 가로로 맞춤
        if (sizes[i][0] < sizes[i][1]) {
            swap(sizes[i][0], sizes[i][1]);
        }

        maxW = max(maxW, sizes[i][0]);
        maxH = max(maxH, sizes[i][1]);
    }

    return maxW * maxH;
}