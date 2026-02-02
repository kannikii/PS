#include <iostream>
#include <vector>
#include <climits>
using namespace std;
static int k=0;
static vector<long long> tree;
void findMin(long long a, long long b);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    
    while((1<<k)<N) k++;
    int base = (1<<k);
    tree.resize(base*2);

    for(int i=0;i<N;i++){
        // N개의 정수 입력
       cin>>tree[base+i]; 
    }
    // min 트리
    for(int i=base-1;i>=1;i--){
        tree[i]=min(tree[i*2],tree[i*2+1]);
    }

    for(int i=0;i<M;i++){
        long long a,b;
        cin>>a>>b;
        findMin(a,b);
    }
}

void findMin(long long a, long long b){
    int start_index = a + (1<<k)-1;
    int end_index = b + (1<<k) -1;
    long long Min = LONG_MAX;

    while(start_index<=end_index){
        if(start_index%2==1){
            Min=min(Min,tree[start_index]);
            start_index++;
        }
        if(end_index%2==0){
            Min = min(Min,tree[end_index]);
            end_index--;
        }
        start_index /=2;
        end_index /=2;
    }

    cout<<Min<<"\n";
}