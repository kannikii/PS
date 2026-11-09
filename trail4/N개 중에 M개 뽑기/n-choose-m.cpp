#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> answer;
vector<bool> visited;
void printAnswer(){
    for(auto it: answer){
        cout<<it<<" ";
    }
    cout<<endl;
}

void choose(int cur){
    if(cur==M+1){
        printAnswer();
        return ;
    }

    for(int i=1;i<=N;i++){
        if(visited[i]==false && (answer.empty()||i>answer.back())){
            answer.push_back(i);
            visited[i]=true;
            choose(cur+1);
            answer.pop_back();
            visited[i]=false;
        }
        
    }
    
    return;
}
int main() {
    cin >> N >> M;

    visited=vector<bool> (N+1,false);
    choose(1);

    return 0;
}
