#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	// 코드 작성
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin>> N;
	map<int, vector<string>> m; // 내림차순

	for(int i=0;i<N;i++){
		int age;
		string name;
		cin>>age>>name;
		m[age].push_back(name);
	}
	for(auto &it:m){
		for(auto &name :it.second){
			cout<<it.first<<" "<<name<<"\n";
		}
	}
	return 0;
}