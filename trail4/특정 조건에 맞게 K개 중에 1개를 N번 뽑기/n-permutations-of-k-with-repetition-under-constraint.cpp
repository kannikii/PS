#include <iostream>
#include <vector>

using namespace std;

int K, N;
vector<int> answer;
void printAnswer(){
    for(auto it : answer){
        
        cout<<it<<" ";
    }
    cout<<endl;
}
void choose(int cur){
    if(cur==N+1){
        printAnswer();
        return;
    }
    for(int i=1;i<=K;i++){
        // 마지막 두 숫자가 i와 같다면 제외
        if (answer.size() >= 2 &&
            answer.back() == i &&
            answer[answer.size() - 2] == i) {
            continue;
        }
        answer.push_back(i);
        choose(cur + 1);
        answer.pop_back();
    }
    
}
int main() {
    cin >> K >> N;

    // Please write your code here.
    // 1~K 까지 중 하나 선택
    // 연속하여 같은 수 3번 이상 나오는 경우는 제외
    choose(1);

    return 0;
}
