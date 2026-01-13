#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
vector<string> split(string line, char op);
int mySum(string str);
int main() {
    string line;
    cin >> line;

    vector<string> str = split(line, '-');
    int answer = 0;
    for (int i = 0; i < str.size(); i++) {
        int temp = mySum(str[i]);
        if (i == 0) {
            answer = temp;
        } else {
            answer -= temp;
        }
    }
    cout << answer << "\n";
}

vector<string> split(string line, char op) {
    // op 연산자 단위로 분할하여 string벡터로 반환하는 함수
    vector<string> result;
    stringstream input(line);
    string temp;
    while (getline(input, temp, op)) {
        result.push_back(temp);
    }
    return result;
}

int mySum(string str) { 
    vector<string> temp=split(str,'+');
    int result=0;
    for(int i=0;i<temp.size();i++){
        result+=stoi(temp[i]);
    }
    return result;
}
