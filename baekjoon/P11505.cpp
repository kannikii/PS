#include <iostream>
#include <vector>
// 구간 곱 구할때 주의사항 
// 빈 노드 1로 표현
// 부모 = (왼쪽 * 오른쪽) % MOD
// 업데이트 시에도 % MOD
// 쿼리 누적 시에도 % MOD
using namespace std;
static int k=0;
static const long long MOD = 1000000007;
static vector<long long> tree;
void update(int idx, long long val);
void intervalProduct(int l, int r);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,K;
    cin>>N>>M>>K;
    // 트리 배열 크기 설정
    while((1<<k)<N) k++;
    int base =(1<<k);
    tree.resize(base*2);
    // 리프 노드 입력
    for(int i=base;i<base+N;i++){
        cin>>tree[i];
    }
    for(int i=base+N;i<tree.size();i++){
        tree[i]=1;
    }
    // 구간 곱 트리  
    for(int i=base-1;i>=1;i--){
        tree[i]=(tree[i*2]*tree[i*2+1])%MOD;
    }

    // 질의
    for(int i=0;i<M+K;i++){
        int a;
        cin>> a;
        if(a==1){
            int b;
            long long c;
            cin>> b>> c;
            update(b,c);
        }else{
            int b,c;
            cin>> b>> c;
            intervalProduct(b,c);
        }
    }
}
void update(int idx, long long val){
    int pos = idx + (1<<k)-1;
    tree[pos]=val%MOD;

    // 부모로 갱신 전파
    pos /=2;
    while(pos>=1) {
        tree[pos]=(tree[pos*2]*tree[pos*2+1])%MOD;
        pos/=2;
    }
}
void intervalProduct(int l, int r){
    int start_index=l+(1<<k)-1;
    int end_index = r+(1<<k)-1;
    long long Product =1;

    while(start_index<=end_index){
        if(start_index%2==1){
            Product=(Product*tree[start_index])%MOD;
            start_index++;
        }
        if(end_index%2==0){
            Product=(Product*tree[end_index])%MOD;
            end_index--;
        }
        start_index/=2;
        end_index/=2;
    }
    cout<<Product<<"\n";
}