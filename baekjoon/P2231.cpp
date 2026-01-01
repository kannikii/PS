#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    

    int length= to_string(N).size();
    //탐색범위 N-자리수*9<=M<=N-1
    int start = N - length * 9;
    if (start < 0) start = 0;

    for(int i=start;i<N;i++){
        int sum = i;
        int temp = i;

        string tempStr;
        tempStr=to_string(temp);
        for(int j=0;j<tempStr.size();j++){
            sum+=(tempStr[j]-'0');
        }
        
        if(sum==N){
            cout<<i<<"\n";
            return 0;
        }
    }
    cout<<0<<"\n";
    return 0;
}