#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> answer;

void sqc(int n){
    if(n>N){
        for(auto it: answer){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=K;i++){
        answer.push_back(i);
        sqc(n+1);
        answer.pop_back();
    }
    
    
}

int main() {
    cin >> K >> N;

    sqc(1);

    return 0;
}
