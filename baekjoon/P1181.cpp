#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// comapare함수 사용자 정의 문자열 크기 -> 길이 같으면 알파벳 순 
bool compare(const string& a, const string& b) {
    if(a.length()!=b.length()){
        return a.length()<b.length();
    }else{
        return a<b;
    }
}

int main() {
    int N;
    cin>>N;

    string A;
    vector<string> v(N);

    for(int i=0;i<N;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end(),compare);


    for(int i=0;i<N;i++){
        if(i > 0 && v[i]==v[i-1]){
            continue;
        }
        cout<<v[i]<<"\n";
    }
}