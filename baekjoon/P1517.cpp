#include <iostream>
#include <vector>

using namespace std;
void mergeSort(int s, int e);
vector<int> A;
vector<int> tmp;

long result=0;   //swap 횟수

int main() {
    int N;
    cin >> N;

    A=vector<int>(N+1,0);
    tmp=vector<int>(N+1,0);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    mergeSort(1, N);
    cout<<result<<"\n";

}

void mergeSort(int s, int e) {
    if (e - s < 1) {
        return;
    }
    int m = s + (e - s) / 2;
    mergeSort(s, m);
    mergeSort(m + 1, e);

    for (int i = s; i <= e; i++) {
        tmp[i] = A[i];
    }

    int k = s;
    int index1 = s;
    int index2 = m + 1;

    // 두 그룹을 병합하는 로직
    while (index1 <= m && index2 <= e) {
        if (tmp[index1] > tmp[index2]) {
            A[k]=tmp[index2];
            k++;
            index2++;
            result+=index2-k;
        }else{
            A[k]=tmp[index1];
            k++;
            index1++;
        }
    }
    // 한쪽 그룹이 모두 선택된 후 남아있는 값 정리하기
    while(index1<=m){
        A[k]=tmp[index1];
        k++;
        index1++;
    }
    while(index2<=e){
        A[k]=tmp[index2];
        k++;
        index2++;
    }
}