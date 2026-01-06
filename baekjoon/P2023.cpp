#include <iostream>
#include <vector>

using namespace std;

void DFS(int num, int digits);
bool isPrime(int num);
static int N;

// 맨앞자리부터 뒷자리까지 한자리씩 추가로 탐색하며 소수인지 판별 -> DFS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> N;

    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);
}

void DFS(int num, int digits) {
    if(digits==N){
        if(isPrime(num)){
            cout<<num<<"\n";
        }
        return;
    }
    for(int i=1;i<=9;i++){
        if(i%2==0){
            continue;
        }else{
            if(isPrime(num*10+i)){
                DFS(num*10+i,digits+1);
            }
        }
    }
}

bool isPrime(int num){
    for(int i=2;i<=num/2;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}