#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N=0;
    cin>>N;

    string numbers;
    cin>>numbers;
    
    int sum=0;
    for(int i=0;i<N;i++){
        sum+=numbers[i]-'0';
    }
    cout<<sum<<'\n';
}