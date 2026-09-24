#include <iostream>
#include <vector>
using namespace std;

int n;
int x[1000];
char dir[1000];

int main() {
    cin >> n;
    vector<vector<int>> v(200001,vector<int>(4,0));
    // v[j][0] : 검은색 개수
    // v[j][1] : 흰색 개수
    // v[j][2] : 회색 여부
    // v[i][3] : 최근 색상 (1:검정색, 2:흰색)

    int now=100000;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
        if(dir[i]=='R'){
            // 오른쪽으로 이동, 검은색으로 칠함
            for(int j=now;j<now+x[i];j++){
                v[j][0]++;
                v[j][3]=1;
                if(v[j][0]>=2&&v[j][1]>=2){
                    v[j][2]++;
                }
            }
            now+=x[i]-1; 
        }else if(dir[i]=='L'){
            // 왼쪽으로 이동, 흰색으로 칠함
            for(int j=now-(x[i]-1);j<=now;j++){
                v[j][1]++;
                v[j][3]=2;
                if(v[j][0]>=2&&v[j][1]>=2){
                    v[j][2]++;
                }
            }
            now-=(x[i]-1);
        }
    }
    int gray=0;
    int black=0;
    int white=0;
    for(int i=0;i<v.size();i++){
        if(v[i][2]!=0){
            gray++;
        }else if(v[i][3]==1){
            black++;
        }else if(v[i][3]==2){
            white++;
        }
    }
    cout<<white<<" "<<black<<" "<<gray<<endl;
    return 0;
}