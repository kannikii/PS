#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // burble sort
    for(int j=0;j<n-1;j++){
        for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            int tmp=a[i];
            a[i]=a[i+1];
            a[i+1]=tmp;
        }
    }
    }
    
    for(auto it : a){
        cout<<it<<" ";
    }
    return 0;
}