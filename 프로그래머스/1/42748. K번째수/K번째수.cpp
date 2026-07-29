#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0;i<commands.size();i++){
        vector<int> tmp;
        int start=commands[i][0]-1;
        int end=commands[i][1]-1;
        int index=commands[i][2]-1;
        
        for(int j=start;j<=end;j++){
            tmp.push_back(array[j]);
        }
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[index]);
    }
    
    return answer;
}