#include <iostream>
#include <vector>
using namespace std;

int N;
int x[100], y[100];

int main() {
    cin >> N;
    vector<vector<int>> v(201,vector<int>(201,0));
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        for(int j=x[i]+100;j<x[i]+108;j++){
            for(int k=y[i]+100;k<y[i]+108;k++){
                v[j][k]=1;
            }
        }
    }

    int count=0;
    for(auto row:v){
        for(auto col:row){
            if(col==1){
                count++;
            }
        }
    }
    cout<<count;

    return 0;
}