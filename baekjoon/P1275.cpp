#include <iostream>
#include <vector>
using namespace std;

static vector<long long> tree;
static int k=0;
void prefixSum(int l, int r);
void update(int idx, long long val);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,Q;
    cin>> N>>Q;
    while((1<<k)<N) k++;

    int base = (1<<k);
    tree.resize(base*2);
    for(int i=base;i<base+N;i++){
        cin>>tree[i];
    }
    for(int i=base-1;i>=1;i--){
        tree[i]=tree[i*2]+tree[i*2+1];
    }
    for(int i=0;i<Q;i++){
        int x,y,a;
        long long b;
        cin>> x>>y>>a>>b;
        if(y>x) prefixSum(x,y);
        else prefixSum(y,x);
        update(a,b);
    }

}

void prefixSum(int l, int r){
    int start_index=l+(1<<k)-1;
    int end_index = r+(1<<k)-1;
    long long sum=0;
    while(start_index<=end_index){
        if(start_index%2==1){
            sum+=tree[start_index];
            start_index++;
        }
        if(end_index%2==0){
            sum+=tree[end_index];
            end_index--;
        }
        start_index/=2;
        end_index/=2;
    }
    cout<< sum<<"\n";
}
void update(int idx, long long val){
    int pos=idx+(1<<k)-1;
    tree[pos]=val;
    // 갱신 전파
    pos /=2;
    while(pos>=1) {
        tree[pos]=tree[pos*2]+tree[pos*2+1];
        pos/=2;
    }
}