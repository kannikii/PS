#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void add(int x);
void remove(int x);
void check(int x);
void toggle(int x);
void all();
void empty();

vector<int> S;

int main() {
    int N;
    cin >> N;

    S=vector<int>(N,0);
    string select;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> select >> x;
        if (select == "add") {
            add(x);
        } else if (select == "remove") {
            remove(x);
        } else if (select == "check") {
            check(x);
        } else if (select == "toggle") {
            toggle(x);
        } else if (select == "all") {
            all();
        } else if (select == "empty") {
            empty();
        }
    }

}

void add(int x){
    S.push_back(x);
}
void remove(int x){
    S.erase(remove(S.begin(),S.end(),x),S.end());
}
void check(int x){
    if(find(S.begin(),S.end(),x)!= S.end()){
        cout <<1<<"\n";
    }else{
        cout <<0<<"\n";
    }
}
void toggle(int x){
    if(find(S.begin(),S.end(),x)!= S.end()){
        add(x);
    }else{
        remove(x);
    }
}
void all(){
    for(int i=1;i<21;i++){
        S[i]=i;
    }
    //i=21부터 남은것들은 없애야함
    
}
void empty(){
    S=vector<int>(0);
}