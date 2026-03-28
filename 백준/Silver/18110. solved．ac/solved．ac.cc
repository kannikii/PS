#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	// 코드 작성
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin>>N;
	if(N==0){
		cout<<0<<"\n";
		return 0;
	}
	vector<int> level;
	for(int i=0;i<N;i++){
		int suggestion;
		cin>>suggestion;
		level.push_back(suggestion);
	}
	// 절사 평균 30% (위 아래로 cut 만큼 제외)
	int cut=(int)(round(N*0.15));

	sort(level.begin(),level.end());

	int count=0;
	int sum=0;
	for(int i=cut;i<level.size()-cut;i++){
		sum+=level[i];
		count++;
	}

	cout<<(int)(round((double)sum/count))<<"\n";

	return 0;
}