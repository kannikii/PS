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

    // selection sort
    // for(int i=0;i<n;i++){
    //     int min=i;
    //     for(int j=i+1;j<n;j++){
    //         if(a[j]<a[min]){
    //             min=j;
    //         }
    //     }
    //     int tmp=a[i];
    //     a[i]=a[min];
    //     a[min]=tmp;
    // }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }


    for(auto it:a){
        cout<<it<<" ";
    }
    return 0;
}