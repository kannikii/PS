#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int score=0;
int nums[12];
vector<int> dst;
int choose(int turn){
    if(turn==n+1){
        return score;
    }
    int ret = 0;
    for(int j=0;j<k;j++){
        int prev = dst[j];

        dst[j]+=nums[turn-1];
        if(prev < m && dst[j] >= m){
            score++;
        }
        ret=max(ret,choose(turn+1));
        if(prev < m && dst[j] >= m){
            score--;
        }
        dst[j]-=nums[turn-1];

    }
    return ret;
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // 1 2 3 4 5 6 7 8 9 10
    // k=3 말 3개 
    // 10번에 도달하면 점수 score++
    // 5 3 2 2 3 3

    // 말 각각의 위치
    dst=vector<int> (k,1);

    
    cout<< choose(1);

    return 0;
}
