#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> st;   // 가격이 아닌 인덱스를 저장

    for (int i = 0; i < prices.size(); i++) {

        // 현재 가격보다 큰 가격들은 지금 답이 확정된다.
        while (!st.empty() && prices[st.top()] > prices[i]) {
            answer[st.top()] = i - st.top();
            st.pop();
        }

        // 아직 답이 정해지지 않은 현재 인덱스 저장
        st.push(i);
    }

    // 끝까지 가격이 떨어지지 않은 경우
    while (!st.empty()) {
        answer[st.top()] = prices.size() - 1 - st.top();
        st.pop();
    }

    return answer;
}