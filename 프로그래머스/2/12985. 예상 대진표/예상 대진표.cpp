#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    // 1 2 -> 1
    // 3 4 -> 2
    // 5 6 -> 3
    // N-1 N -> N/2
    
    
    
    // 1~n까지 숫자 있음 
    while(1){
        if(a==b){
            break;
        }
        
        a=(a+1)/2;
        b=(b+1)/2;
        answer++;
    }
    
    return answer;
}