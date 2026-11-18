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
    cout<<endl;

}

void choose(int cur){
    if(cur==n+1){
        printAnswer();
        return;
    }
    for(int i=n;i>0;i--){
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
    visited.resize(n+1);
    // Please write your code here.
    choose(1);
    
    return 0;
}
