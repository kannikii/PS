#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> v(N);

    int count=0;


    for(int i=0;i<N;i++){
        bool visited[26] = {false};
        char prev = 0;
        bool isGroup=true;
        cin>>v[i];
        for(int j=0;j<v[i].size();j++){
            
            if(v[i][j]==prev){
                //연속이므로 ok
                prev=v[i][j];
                visited[v[i][j]-'a']=true;
            }else{
                if(visited[v[i][j]-'a']==true){
                    //탈락
                    isGroup=false;
                    break;
                }
                prev=v[i][j];
                visited[v[i][j]-'a']=true;
            }
        }
        if(isGroup) count++;
    }
    
    cout<<count<<"\n";
}