#include <iostream>
using namespace std;
//투 포인터 O(n)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int start_index=1;
    int end_index=1;
    int sum=1;
    int count=1;

    while(end_index!=N){
        if(sum==N){
            count++;
            end_index++;
            sum+=end_index;
        }else if(sum>N){
            sum-=start_index;
            start_index++;
        }else if(sum<N){
            end_index++;
            sum+=end_index;
        }
    }
    cout<<count<<"\n";
}