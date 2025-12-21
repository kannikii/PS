#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin>>N;
    int input[1000];
    
    for(int i=0;i<N;i++){
        cin>>input[i];
    }

    int sum=0;
    int M=0;
    for(int i=0;i<N; i++){
        if(input[i]>M){
            M=input[i];
        }
        sum+=input[i];
    }
    cout<<double(sum*100.0/M/N);
}