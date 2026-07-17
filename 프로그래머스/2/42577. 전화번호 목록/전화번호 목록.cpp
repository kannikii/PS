#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer=true;
    
    // phone_book의 번호를 오름차순 정렬
    // 가장 짧은 번호가 다른번호에 접두사로 포함되는지 확인
    // 포함된다면 확인 중단하고 answer = false
    
    sort(phone_book.begin(),phone_book.end());
    
    for(int i=0;i<phone_book.size()-1;i++){
        if(phone_book[i]==phone_book[i+1].substr(0,phone_book[i].size())){
            return false;
        }
    }
    return answer;
}