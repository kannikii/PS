#include <iostream>
#include <cmath>
using namespace std;
// φ(n)=n(i=1∏m​(1−1/p^i​))
// 오일러 피 함수 
// result←result×(1−1/p​)=result−result/p​
// 소인수 p를 하나 찾을 때마다 결과값(result)에 (1 - 1/p)를 반영한다.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long n;
    cin>>n;
    // φ(n)=n×(...) 공식이 n부터 시작하므로 result 초기값=n
    long result = n;

    for(int p=2; p<=sqrt(n);p++){
        if(n%p==0){ //소인수 p를 발견할 때마다
            result=result-result/p;
            // 해당 소인수 지우기
            while(n%p==0){
                n/=p;
            }
        }
    }
    if(n>1) { //아직 소인수 구성이 남아있는 경우
        // 반복문에서 제곱근까지만 탐색했기 때문에 1개의 소인수가 누락되는 케이스 처리
        result=result-result/n;
    }
    cout<< result<<"\n";
}