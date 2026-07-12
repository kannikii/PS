#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int item : numbers){
        answer.push_back(item*2);
    }
    return answer;
}