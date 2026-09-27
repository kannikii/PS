#include <iostream>
#include <vector>
using namespace std;

int n;
int x1[10], y1[10];
int x2[10], y2[10];

int main() {
    cin >> n;
    vector<vector<int>> v(201,vector<int>(201,0));
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        if(i%2==0){     // 빨간색
            for(int j=x1[i]+100;j<x2[i]+100;j++){
                for(int k=y1[i]+100;k<y2[i]+100;k++){
                    v[j][k]=1;
                }
            }
        }else{          // 파란색
            for(int j=x1[i]+100;j<x2[i]+100;j++){
                for(int k=y1[i]+100;k<y2[i]+100;k++){
                    v[j][k]=2;
                }
            }
        }
    }

    int count=0;
    for(auto row:v){
        for(auto color:row){
            if(color==2){
                count++;
            }
        }
    }

    cout<<count;
    return 0;
}