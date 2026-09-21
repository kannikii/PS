#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int x1[100], x2[100];

int main() {
    cin >> n;
    vector<int> v(200,0);
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        for(int j=x1[i]+100;j<=x2[i]+100-1;j++){
            v[j]++;
        }
    }
    // 입력 받은 인덱스 + 100으로 시작해야함 
    // 종료 구간 -1 로 인덱스 사용해야함
    int max=*max_element(v.begin(),v.end());
    cout<<max;
    return 0;
}