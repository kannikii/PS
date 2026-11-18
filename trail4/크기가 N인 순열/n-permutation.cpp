#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> answer;
vector<bool> visited;
void printAnswer(){
    for(auto it: answer){
        cout<<it<<" ";
    }
    cout<<"\n";
}
void choose(int cur){
    if(cur==n+1){
        printAnswer();
        return;

    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            answer.push_back(i);
            visited[i]=true;
            choose(cur+1);
            answer.pop_back();
            visited[i]=false;
        }

    }

}

int main() {
    cin >> n;
    visited=vector<bool> (n+1,false);
    // Please write your code here.

    choose(1);

    return 0;
}
