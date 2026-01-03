#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    // 내가 푼 풀이 
    string N;
    cin>>N;

    vector<int> A;

    for(int i=0;i<N.size();i++){
        A.push_back(N[i] - '0');
    }

    sort(A.begin(),A.end(),greater<int>());

    for(int i=0;i<N.size();i++){
        cout<<A[i];
    }
    return 0;


}