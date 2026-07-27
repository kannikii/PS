#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool cmp1(pair<string, int>v1, pair<string,int>v2){
    return v1.second > v2.second;
}
bool cmp2(pair<int,int>v1, pair<int,int> v2){
    if(v1.second==v2.second){
        return v1.first<v2.first;
    }
    return v1.second > v2.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // classic0, classic1, classic3 이렇게 저장하고 각각 plays 기록해두고 싶음 
    // 장르별 plays 총합 저장
    // 그리고 plays 내림차순 정렬(재생 수 같으면 번호 낮은순 정렬)(compare), 
    // 가장 높은 두개 번호 선택 반환 
    // pop도 마찬가지 정렬 후 두개 번호 반환 
    // 장르별 plays 총합 내림차순 장르 순서로 두개 번호씩 answer.push_back()
    map<string,int> totalPlays;
    map<string,vector<pair<int,int>>> m;
    for(int i=0;i<plays.size();i++){
        totalPlays[genres[i]]+=plays[i];
        m[genres[i]].push_back({i,plays[i]});
    }
    
    // 장르 순서 정렬
    vector<pair<string, int>> v;
    for(auto &it:totalPlays){
        v.push_back({it.first,it.second});
    }
    sort(v.begin(),v.end(),cmp1);
    
    
    // 장르별 순서 정렬
    for(auto &it:m){
        sort(it.second.begin(),it.second.end(),cmp2);    
    }
    
    for(int i=0;i<v.size();i++){
        answer.push_back(m[v[i].first][0].first);
        if(m[v[i].first].size()>=2){
            answer.push_back(m[v[i].first][1].first);
        }else continue;
    }
    
    
    return answer;
}