#include <iostream>
using namespace std;

int main() {
	// 코드 작성
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin>>N;
	int count =1;
	int num=666;
	while(true){
		if(count==N){
			cout<<num<<"\n";
			break;
		}
		num++;
		// num에 666이 포함되면 count++
		string temp=to_string(num);
		if(temp.find("666")!=string::npos){
			count++;
		}
		
	}
	return 0;
}