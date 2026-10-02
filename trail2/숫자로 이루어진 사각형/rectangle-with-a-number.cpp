#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;
    int a=1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(a>9){
                a=1;
            }
            cout<<a<<" ";
            a++;
        }
        cout<<endl;
    }

    return 0;
}