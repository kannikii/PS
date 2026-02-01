#include <iostream>
// set STL로 쉽게 풀수 있으나, 트라이 연습

using namespace std;

class Node {
   public:
    Node* next[26];
    bool isEnd;
    // 생성자
    Node() : isEnd(false) { fill(next, next + 26, nullptr); }
    // 소멸자
    ~Node() {
        for (auto& child : next) delete child;
    }
    // 문자열을 입력으로 받아 삽입하는 함수
    void insert(const char* key) {
        if (*key == 0) {    // key의 끝값 도달하면 (key=='\0') 
            isEnd = true;   // 이때 노드를 단어 끝으로 표시
        } else {
            int next_index = *key - 'a';
            // 문자 -> 인덱스화
            if (next[next_index] == nullptr) {  // 해당 문자로 가는 길이 없으면
                next[next_index]=new Node();    // 새 노드 생성
            }
            next[next_index] -> insert(key+1);  // 다음 문자로 이동, 포인터 증가
        }
    }
    // 문자열 입력으로 받아 트라이에 존재하는 노드(위치)를 반환하는 함수
    Node *find(const char* key){
        if(*key==0){        // key의 끝에 도달한 경우
            return this;    // 현재 노드를 반환
        }
        int next_index=*key-'a';
        if(next[next_index]==nullptr){  // 해당 문자로 가는 길이 없으면
            return nullptr;             // 문자열 자체가 없음 
        }
        return next[next_index]-> find(key+1);  // 다음 문자로 이동, 포인터 증가
    }
    
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    Node* root = new Node();

    while (n > 0) {  	// 트라이 자료구조 구축하기
        char text[501];
        cin >> text;
        root->insert(text);
        n--;
    }

    int count = 0;
    while (m > 0) {  	// 트라이 자료구조 검색하기
        char text[501];
        cin >> text;
        Node* result = root->find(text);
        if (result && result->isEnd) {
            count++; 	// S집합에 포함되는 문자열
        }
        m--;
    }
    cout << count << "\n";
}