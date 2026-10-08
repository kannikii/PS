#include <iostream>

using namespace std;

int n;
int arr[50];

void absn(int &a) {
    if(a<0){
        a*=(-1);
    }
    
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        absn(arr[i]);
        cout<<arr[i]<<" ";
    }

    
    return 0;
}