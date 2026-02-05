#include <iostream>
#include <vector>

using namespace std;
vector<long long> fact;

static vector<long long> sequence;
static vector<bool> visited;
int main() {
    int N;
    cin>>N;
    
    fact.resize(N+1);
    fact[0]=1;
    for(int i = 1; i <= N; i++){
        fact[i] = fact[i-1] * i;
    }

    sequence.resize(N+1);
    visited.resize(N+1,false);
    
    int cmd;
    cin>>cmd;
    if(cmd==1){
        // K번째 순열 구하기
        // 1~N까지의 숫자 1,2,3,4 가 1번쨰 순열
        // 각 자리별 경우의 수 N!,(N-1)!,(N-2)!,(N-3)!,...,(2!),1!
        
        // 앞자리 하나 고정해두고, 앞자리 몇의 묶음에 속하는지 확인 k/(N-1)!
        // 한 묶음당 N-1!씩 있으므로 (N자리 숫자 앞자리 고정해두면 (N-1)!개의 경우의 수 발생)
        // k/(N-1)! 의 값에 따라 첫번째 숫자가 정해짐. +1)
        // 1 _ _ _ 인 상태  
        // 남은 숫자 [2,3,4,...N-1,N] k는 여전히 2(3번째 순열 찾기) 
        // 이제 둘째자리 고정해두고, 다시 k/(N-2)! 의 값이 남은 숫자의 ~번째이다. (3)
        // 1 3 _ _ 인 상태
        // 마찬가지로 매 남은 자리 마다 반복된다. 남은 숫자 개수 m이라 하면,
        // 현재 자리 하나 고정해서 또 (m-1)! 개씩 묵음 , k/(m-1)! -> 몇번째 묶음에 있는지 (다음 자리숫가 남아있는 수의 몇번째인지)
        // k = k % (m-1)!
        // 다음 자리로 이동 
        long long K;
        cin>>K;

        for(int i=1;i<=N;i++){  // i번째 자리 들어갈 숫자 구하는 루프
            int cnt=1;          // 현재 보고있는 숫자(j)가 남은 숫자 중 몇번째 후보인가? 
            for(int j=1;j<=N;j++){  // 숫자 후보 탐색
                if(visited[j]){     // 이미 쓴 숫자는 건너뜀
                    continue;
                }
                // 여기 이해가 중요
                if(K<=cnt * fact[N-i]){ // j를 i번째 자리에 놓았을 때 생기는 묶음 안에 내가 찾는 K번째 순열이 포함되는가?
                    K-=((cnt-1)*fact[N-i]); // 앞에서 건너뛴 묶음의 순열 개수를 빼서 이제 이 묶음안에서 몇번째인지로 바꿈
                    sequence[i]=j;  // 정답 순열
                    visited[j]=true;    
                    break;
                }
                cnt++;  // j루프가 하나 확인하고 반복하면서 증가한다.
            }

        }
        for(int i=1;i<=N;i++){
            cout<<sequence[i]<<" ";
        }
        cout<<"\n";
    }else if(cmd==2){
        long long K=1;
        for(int i=1;i<=N;i++){
            cin>>sequence[i];

            long long cnt=0;
            for(int j=1;j<sequence[i];j++){ // 입력받은 순열을 하나씩 확인
                if(visited[j]==false){
                    cnt++;
                }
            }
            K+=cnt*fact[N-i];
            visited[sequence[i]]=true;
        }
        cout<<K<<"\n";
    }
}