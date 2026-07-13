#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    // 두개 뽑아서 다 더하고 set에 저장하면 중복 처리도 됨
    set<int> s;
    for(int i=0;i<numbers.size();i++){
        for(int j=i+1;j<numbers.size();j++){
            s.insert(numbers[i]+numbers[j]);
        }
    }
    for(int i: s){
        answer.push_back(i);
    }
    return answer;
}