#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >>N;
    vector<int> A(N,0);
    vector<int> NGE(N,-1); //정답 배열 
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    //스택에 값이 아닌 인덱스로 넣기
    stack<int> myStack;
    for(int i=0;i<N;i++){
        //스택에 새로 들어오는 수가 top보다 크면 그 수는 오큰수 NGE가 된다.
        //오큰수를 구한 후 수열에서 오큰수가 존재하지 않는 숫자에 -1을 출력해야 한다.
        while(!myStack.empty() && A[myStack.top()]<A[i]){
            NGE[myStack.top()]=A[i];
            myStack.pop();
        }
        myStack.push(i);
    }
    for(int i:NGE){
        cout<<i<<" ";
    }
    
}