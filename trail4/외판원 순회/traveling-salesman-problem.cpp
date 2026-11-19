#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int A[10][10];
vector<int> answer;
vector<bool> visited;
int minSum=INT_MAX;
int tmpSum=0;
int choose(int cur){
    // 마지막에 3 / 7 / 9 더해야함
    if(cur==n+1){
        int back=A[answer.back()-1][0];
        if(back == 0) return INT_MAX;
        return tmpSum+back;
    }
    int res=INT_MAX;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            int w=A[answer.back()-1][i-1];
            if(w==0) continue;
            tmpSum+=w;
            answer.push_back(i);
            visited[i]=true;

            res=min(res,choose(cur+1));

            tmpSum-=w;
            answer.pop_back();
            visited[i]=false;
        }
    }
    return res;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    visited.resize(n+1);
    answer.push_back(1);
    visited[1]=true;
    minSum=min(minSum,choose(2));

    cout<<minSum;
    return 0;
}
