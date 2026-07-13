#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int a=arr1.size();
    int b=arr1[0].size();
    
    int c=arr2.size();
    int d=arr2[0].size();
    
    answer.resize(a, vector<int>(d, 0));
    
    // 행렬의 곱셈 구현
    // 행렬 answer[i][j]를 구하려면 arr1[i][*], arr2[*][j] 각각 곱해서 모두 더함
    // 3중 for문 -> O(N^3), 입력 수 100이하 10^9 밑이므로 1초 안으로 가능
    for(int i=0;i<a;i++){
        for(int j=0;j<d;j++){
            for(int k=0;k<b;k++){
                answer[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }
    }
    

    
    return answer;
}