#include <iostream>
#include <algorithm>
using namespace std;

int main()  {
    int A[]={5,3,2,4,1};
    int n = sizeof(A)/sizeof(A[0]);
    sort(A,A+n,greater<int>());
    
    for(int i =0;i<n;i++){
        cout << A[i] << " " ;
    }
}