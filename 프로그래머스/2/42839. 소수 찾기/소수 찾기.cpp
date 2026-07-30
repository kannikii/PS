#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

// 중복 처리 (예: 011, 11 같은 숫자)
unordered_set<int> nums;

// 숫자별 방문 배열
bool visited[7];

bool isPrime(int n){
    if(n<2) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    
    return true;
}

void dfs(string current,string numbers){
    
    // 빈 문자열이 아니면 숫자로 변환하여 저장
    if(!current.empty()){
        nums.insert(stoi(current));
    }
    
    for(int i=0;i<numbers.size();i++){
        
        // numbers[i] 사용했으면 넘김
        if(visited[i]) continue;
        
        visited[i]=true;
        dfs(current+numbers[i],numbers);
        visited[i]=false;
    }
}



int solution(string numbers) {
    int answer = 0;
    
    // 가능한 모든 숫자 조합 중복없이 저장
    dfs("",numbers);
    
    
    // 소수 개수 세기
    for(auto it: nums){
        if(isPrime(it)) answer++;
    }

    return answer;
}