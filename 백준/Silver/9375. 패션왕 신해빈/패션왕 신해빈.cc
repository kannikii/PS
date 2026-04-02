#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;

		// category별 하나씩 선택 가능 
		// 선택 가지 수 = (카테고리별 아이템 수 +1)^카테고리 수 -1 
		// 알몸인 경우 1가지 제외 (-1)

		// 카테고리별 아이템 개수 관리하기 위함
		map<string,vector<string>> m;
		for(int i=0;i<N;i++){
			string item;
			string category;
			cin>> item>>category;

			m[category].push_back(item);
		}

		int count=1;
		for(auto it:m){
			count*=(it.second.size()+1);
		}
		cout<<count-1<<"\n";

	}
	return 0;
}