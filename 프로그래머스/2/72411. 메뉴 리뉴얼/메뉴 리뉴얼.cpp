#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
map<string,int> combi;

void combination(string src, string dst, int depth){
    if(dst.size()==depth) {
        combi[dst]++;
    }
    else {
        for(int i=0;i<src.size();i++){
            combination(src.substr(i+1),dst+src[i],depth);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    // 주문 오름차순 정렬
    for(string &order : orders){
        sort(order.begin(),order.end());
    }
    
    // 코스길이별 주문에서 가능한 조합 따져보기
    for(int len:course){
        for(string order: orders){
            // 조합생성
            combination(order,"",len);
            
        }
        int maxOrder=0;
        // 메뉴길이별 조합에서 최대 주문 개수 구하기
        for(auto it:combi){
            maxOrder=max(maxOrder,it.second);
        }
        
        // 주문 횟수가 2회이상이면서, 가장 많이 주문된 구성 answer에 추가
        for(auto it:combi){
            if(maxOrder>=2&& it.second==maxOrder){
                answer.push_back(it.first);
            }
        }
        combi.clear();
    }
    
    sort(answer.begin(),answer.end());
    return answer;
}