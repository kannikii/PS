#include <iostream>
#include <vector>
using namespace std;

int n;
int x[1000];
char dir[1000];

int main() {
    cin >> n;
    vector<int> v(200001,0);
    int now=100000;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
        if(dir[i]=='R'){
            // 오른쪽으로 이동하며 검은색으로 만듬
            for(int j=now;j<x[i]+now;j++){
                v[j]=1;
            }
            now+=x[i]-1;
        }else if(dir[i]=='L'){
            // 왼쪽으로 이동하며 흰색으로 만듬
            for(int j=now-(x[i]-1);j<=now;j++){
                v[j]=2;
            }
            now-=x[i]-1;
        }
    }
    int black=0;
    int white=0;
    for(auto it: v){
        if(it==1){
            black++;
        }else if(it==2){
            white++;
        }
    }
   
    cout<<white<<" "<<black;
    return 0;
}