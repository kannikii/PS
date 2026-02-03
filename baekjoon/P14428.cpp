#include <iostream>
#include <vector>
#include <climits>
using namespace std;
static vector<long long> tree;
static vector<long long> sequence;
static int N;
static int k=0;
void update(int idx, long long val);
void findMinIdx(int l, int r);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    sequence.resize(N+1);
    while((1<<k)<N) k++;
    int base=1<<k;
    tree.resize(base*2,LLONG_MAX);
    for(int i=base;i<base+N;i++){
        cin>>tree[i];
    }   
    for(int i=1;i<=N;i++){
        sequence[i]=tree[base+i-1];
    }
    for(int i=base-1;i>=1;i--){
        tree[i]=min(tree[i*2],tree[i*2+1]);
    }
    int M;
    cin>>M;
    for(int i=0;i<M;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        if(a==1){
            update(b,c);
        }else if(a==2){
            findMinIdx(b,c);
        }
    }

}
void update(int idx, long long val){
    int pos = idx+(1<<k)-1;
    tree[pos]=val;
    pos/=2;
    while(pos>=1){
        tree[pos]=min(tree[pos*2],tree[pos*2+1]);
        pos/=2;
    }
    sequence[idx]=val;
}
void findMinIdx(int l, int r){
    int start_index=l+(1<<k)-1;
    int end_index = r+(1<<k)-1;
    long long Min=LLONG_MAX;
    while(start_index<=end_index){
        if(start_index %2==1){
            Min=min(Min,tree[start_index]);
            start_index++;
        }
        if(end_index%2==0){
            Min=min(Min,tree[end_index]);
            end_index--;
        }
        start_index/=2;
        end_index/=2;
    }
    // Min을 가리키는 인덱스를 찾아서 그걸 다시 변환하여서 반환해야함
    for(int i = l; i <= r; i++){
        if(sequence[i] == Min){
            cout << i << "\n";
            return;
        }
    }
}
