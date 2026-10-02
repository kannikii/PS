#include <iostream>
#include <cmath>
#include <numeric>
using namespace std;

int main() {
    
    int n,m;
    cin>>n>>m;
    int answer=gcd(n,m);

    cout<<answer;
    return 0;
}