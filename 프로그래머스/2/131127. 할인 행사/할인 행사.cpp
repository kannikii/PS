#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
// 미친 쌀숭이 정현이 보법이 다르노;;
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    // {want,number} 해시에 넣어서 
    // discount 하나씩 순회(시작날짜) 하며 10일까지 해시에있는 값 0 만들어지면
    //  -> true화, 시작 날짜 return
    // 순회 이후 해시에 있는 값 0이 되지않고 남아있으면, 시작날짜 +1 다시 반복
    // 시작날짜 전부 순회해도 불가능 하다면 (false로 남아있음) return 0;
    unordered_map<string,int> um;
    
    for(int i=0;i<number.size();i++){
        um[want[i]]=number[i];
    }
    int size=discount.size();
    int count=0;
    for(int i=0;i<=size-10;i++){
        unordered_map<string,int> copy = um;
        bool status=false;
        for(int j=i;j<i+10;j++){
            if(copy.count(discount[j]) && copy[discount[j]]>=1){
                copy[discount[j]]--;
                status=true;
            }else{
                status=false;
                break;
            }
        }
        if(status==true){
            count++;
        }
    }
    answer=count;
    return answer;
}