    #include <iostream>
    #include <queue>
    #include <vector>

    using namespace std;
    static int N,M;
    static vector<vector<int>> adj_list;
    static vector<bool> visited;
    static vector<int> answer;
    void BFS(int index);
    int main() {
        cin>> N>>M;
        adj_list.resize(N+1);
        visited.resize(N+1);
        answer.resize(N+1);

        for(int i=0;i<M;i++){
            int A,B;
            cin>>A>>B;
            adj_list[A].push_back(B);
        }

        for(int i=0;i<=N;i++){
            fill(visited.begin(),visited.end(),false);
            BFS(i);
        }
        int maxVal=0;

        for(int i=1;i<=N;i++){
            maxVal=max(maxVal,answer[i]);
        }
        for(int i=1;i<=N;i++){
            if(answer[i]==maxVal){
                cout<<i<<" ";
            }
        }
    }

    void BFS(int index){
        queue<int> q;
        q.push(index);
        visited[index]=true;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int i: adj_list[cur]){
                if(visited[i]==false){
                    visited[i]=true;
                    answer[i]++;
                    q.push(i);
                }
            }
        }
    }