#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> firstP = {1,2,3,4,5};           // 5개 반복
vector<int> secondP = {2,1,2,3,2,4,2,5};    // 8개 반복
vector<int> thirdP = {3,3,1,1,2,2,4,4,5,5}; // 10개 반복

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> count(3,0);
    
    for(int i=0;i<answers.size();i++){
        if(answers[i]==firstP[i%5]) count[0]++;
        if(answers[i]==secondP[i%8]) count[1]++;
        if(answers[i]==thirdP[i%10]) count[2]++;
        
        
    }
    // count가 가장 많은 사람을 넣어야함 
    int maxCount = max(count[2], max(count[0], count[1]));
    
    for(int i=0;i<3;i++){
        if(maxCount==count[i]){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}