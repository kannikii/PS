#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000];

int main() {
    cin >> N;
    int maxC=0;
    int cnt=0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if(i==0||arr[i-1]!=arr[i]){
            cnt=1;
        }
        else{
            cnt++;
        }
        maxC=max(maxC,cnt);
    }

   cout<<maxC;
    return 0;
}