#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

string solution(string s) {
    string answer = "";
    // s를 공백 기준 파싱
    // stoi 화 해서 int 벡터에 넣기
    // sort 하고 최솟값, 최댓값 저장
    // answer배열에 문자열로 변환해서 순서대로 저장 (중간에 공백 추가)
    istringstream ss(s);
    string token;
    vector<int> numbers;
    while(ss>>token){
        numbers.push_back(stoi(token));
    }
    
    sort(numbers.begin(),numbers.end());
    
    int minV=numbers[0];
    int maxV=numbers[numbers.size()-1];
    
    answer+=to_string(minV)+" "+to_string(maxV);
    
    return answer;
}