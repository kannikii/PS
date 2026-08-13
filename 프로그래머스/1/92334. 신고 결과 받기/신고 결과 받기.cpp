#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);

    // 피신고자 -> 신고받은 횟수
    unordered_map<string, int> reported;

    // 신고자 -> 신고한 유저 목록
    unordered_map<string, set<string>> user_reports;

    // 신고 기록 저장
    for(auto it : report) {
        string reporter;
        string reported_user;

        // it를 공백 기준으로 분리
        stringstream ss(it);
        ss >> reporter >> reported_user;

        // 신고 관계 저장
        user_reports[reporter].insert(reported_user);
    }
    
    
    
    // 신고받은 횟수 계산
    for(auto &it : user_reports) {
        for(auto &user : it.second) {
            reported[user]++;
        }
    }

    // 정지된 유저를 신고한 사람에게 메일
    for(auto &it : user_reports) {
        for(auto &user : it.second) {

            if(reported[user] >= k) {

                // 신고자의 id 위치 찾기
                for(int i = 0; i < id_list.size(); i++) {
                    if(id_list[i] == it.first) {
                        answer[i]++;
                        break;
                    }
                }
            }
        }
    }

    return answer;
}