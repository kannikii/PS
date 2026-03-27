#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// 코드 작성
	int N;
	cin>>N;
	vector<pair<int,int>> pos;
	for(int i=0;i<N;i++){
		int x,y;
		cin>>x>>y;
		pos.push_back({x,y});
	}
	sort(pos.begin(),pos.end());
	for(auto it:pos){
		cout<<it.first<<" "<<it.second<<"\n";
	}
	return 0;
}