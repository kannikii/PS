#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const pair<int,int> &x, const pair<int,int> &y){
	if (x.second == y.second) 
        return x.first < y.first;  // 같으면 first 비교
    return x.second < y.second;    // 우선 second 기준
}
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
	sort(pos.begin(),pos.end(),compare);
	for(auto it:pos){
		cout<<it.first<<" "<<it.second<<"\n";
	}
	return 0;
}