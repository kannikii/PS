#include <iostream>

using namespace std;

int main() {
    int T;
    cin>>T;
    int H,W,N;
    
    for(int i=0;i<T;i++){
        cin >> H>>W>>N;
        int floor = (N - 1) % H + 1;
        int room  = (N - 1) / H + 1;

        cout << floor * 100 + room << '\n';
    }

}