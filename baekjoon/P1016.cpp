#include <iostream>
#include <vector>

using namespace std;

int main() {
    long min,max;
    cin>> min>> max;
    vector<bool> check(max-min+1);
    for(int i=2;i*i<max;i++){
        long pow=i*i;
        long start_index=min/pow; //시간 제한 때문에 min~max범위만 배열 생성

        if(min%pow!=0) start_index++; 

        for(long j=start_index; pow*j<=max; j++){ 
            check[j*pow-min]=true; 
        }
    }

    int cnt=0;
    for(int i=0;i<max-min+1; i++){
        if(!check[i]){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
}