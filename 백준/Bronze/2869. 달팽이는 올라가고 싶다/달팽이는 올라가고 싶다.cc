#include <iostream>
using namespace std;

int main() {
	// 코드 작성
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A,B,V;
	cin>>A>>B>>V;
	// int count=0;
	// int days=0;
	// while(true){
	// 	days++;
	// 	count+=A;
	// 	if(count>=V){
	// 		break;
	// 	}
	// 	count-=B;
	// }
	// 위 코드로 실패함 시간복잡도 O(V)라서,
	// V의 최댓값이 10^9이라서 O(1)으로 해결해야함

	long long days = (V - A) / (A - B);
    if ((V - A) % (A - B) != 0) days++;

    cout << days + 1 << '\n'; // 마지막 날 포함

	return 0;
}