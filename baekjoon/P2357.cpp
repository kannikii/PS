#include <iostream>
#include <vector>
#include <climits>
using namespace std;
static int k=0;
static vector<long long> tree;
static vector<long long> treeMax;
static vector<long long> treeMin;
void findMax(int l,int r);
void findMin(int l,int r);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin>>N>>M;

    while((1<<k)<N) k++;
    int base = (1<<k);
    tree.resize(base*2,0);
    treeMax.resize(base*2,0);
    treeMin.resize(base*2,0);
    for(int i=base;i<base+N;i++){
        cin>>tree[i];
        treeMax[i]=treeMin[i]=tree[i];
    }
    // Max Tree, Min Tree
    for(int i=base-1;i>=1;i--){
        treeMax[i]=max(treeMax[i*2],treeMax[i*2+1]);
        treeMin[i]=min(treeMin[i*2],treeMin[i*2+1]);
    }
    

    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        findMin(a,b);
        findMax(a,b);
        cout<<"\n";
    }
}
void findMax(int l, int r){
    int start_index = l+(1<<k)-1;
    int end_index = r+(1<<k)-1;
    long long Max=LLONG_MIN;
    while(start_index<=end_index){
        if(start_index%2==1){
            Max=max(Max,treeMax[start_index]);
            start_index++;
        }
        if(end_index%2==0){
            Max = max(Max,treeMax[end_index]);
            end_index--;
        }
        start_index/=2;
        end_index/=2;
    }
    cout<<Max<<" ";
}
void findMin(int l, int r){
    int start_index = l+(1<<k)-1;
    int end_index = r+(1<<k)-1;
    long long Min=LLONG_MAX;
    while(start_index<=end_index){
        if(start_index%2==1){
            Min=min(Min,treeMin[start_index]);
            start_index++;
        }
        if(end_index%2==0){
            Min = min(Min,treeMin[end_index]);
            end_index--;
        }
        start_index/=2;
        end_index/=2;
    }
    cout<<Min<<" ";
}