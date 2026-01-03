#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    // 골드2 버블정렬 아이디어
    // N의 최대 크기가 50만이므로 버블정렬 그대로 사용하면 안됨 (n^2)
    // 문제가 원하는 것이 버블정렬 과정에서 i루프 반복 당 swap이 한번도 일어나지 않은 i루프를 찾는것이다.
    // i루프 한번에서 특정원소 하나 당 swap이 1칸씩만 가능하므로 
    // 정렬 후 인덱스 - 정렬 전 인덱스 차이만큼 이동이 필요하다는 것을 활용해
    // 최대로 이동이 많았던, 즉 인덱스 값 차이가 가장 큰 만큼 i루프가 필요하다는 것을 알 수 있다.
    // 문제 배열은 1부터 채우므로 최대 인덱스 차이값 +1 을 해주는 것이 정답이다.

    vector<pair<int,int>> sorted(N);
    vector<pair<int,int>> orign(N);
    vector<int> result(N,0);
    for (int i = 0; i < N; i++) {
        cin >>sorted[i].first;
        sorted[i].second=i;
        //복사
        orign[i].first=sorted[i].first;
        orign[i].second=i;
    }
    sort(sorted.begin(),sorted.end());
    int max=result[0];
    for(int i=0;i<N;i++){
        result[i]=sorted[i].second-orign[i].second;
        if(max<result[i]){
            max=result[i];
        }
    }
    cout<<max+1<<"\n";

    // 버블 정렬 과정에서 swap이 한번도 일어나지 않은 i루프를 찾기-> 한번에 1칸씩만 왼쪽으로 이동가능
    // bool change = false;
    // for (int i = 1; i <= N + 1; i++) {
    //     change = false;
    //     for (int j = 1; j <= N - i; j++) {
    //         if (A[j] > A[j + 1]) {
    //             change = true;
    //             swap(A[j], A[j + 1]);
    //         }
    //     }
    //     if (change == false) {
    //         cout << i << "\n";
    //         break;
    //     }
    // }


}