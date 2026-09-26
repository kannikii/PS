#include <iostream>
#include <vector>
using namespace std;

int N;
int x1[10], y1[10];
int x2[10], y2[10];

int main() {
    cin >> N;
    vector<vector<int>> v(201,vector<int>(201,0));
    for (int i = 0; i < N; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        
        for(int j=x1[i]+100;j<x2[i]+100;j++){
            for(int k=y1[i]+100;k<y2[i]+100;k++){
                if(j>=x1[i]+100&&j<x2[i]+100){
                    v[j][k]=1;
                }
            }
        }
    }
    int count=0;
    for(auto row : v){
        for(auto x : row){
            if(x == 1){
                count++;
            }
        }
    }
    cout<<count;

    return 0;
}