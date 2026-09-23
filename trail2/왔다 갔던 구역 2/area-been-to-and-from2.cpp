#include <iostream>
#include <vector>
using namespace std;

int n;
int x[100];
char dir[100];

int main() {
    cin >> n;
    vector<int> v(2001,0);
    // offset : 1000, 구간으로 세기
    int now=1000;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
        if(dir[i]=='R'){
            for(int j=now;j<=now+x[i]-1;j++){
                v[j]++;
            }
            now+=x[i];
        }
        else if(dir[i]=='L'){
            for(int j=now-x[i];j<=now-1;j++){
                v[j]++;
            }
            now-=x[i];
        }
    }
    int count=0;
    for(auto it: v){
        if(it>=2){
            count++;
        }
    }
    cout<<count;
    return 0;
}