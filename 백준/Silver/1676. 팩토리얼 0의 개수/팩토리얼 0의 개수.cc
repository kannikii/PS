#include <iostream>
using namespace std;
int fact(int N);
int main() {
    // 코드 작성
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    // 직접 팩토리얼 계산 -> 문자열 변환 -> 0개수 세기 -> 오버플로우
    // long long A=fact(N);
    // string B=to_string(A);
    // int count=0;
    // for(int i=B.size()-1; i>=0;i--){
    // 	if(B[i]!='0'){
    // 		break;
    // 	}
    // 	if(B[i]=='0'){
    // 		count++;
    // 	}
    // }
    
    int count = 0;

    while (N > 0) {
        N /= 5;
        count += N;
    }
	cout<<count<<"\n";
    return 0;
}
// int fact(int N){
// 	if(N<=1){
// 		return 1;
// 	}
// 	return fact(N-1)*N;
// }