#include <iostream>
#include <cmath>
#include <numeric>
using namespace std;

int main() {
    // Please write your code here.
    int n,m;
    cin>>n>>m;
    int answer=lcm(n,m);

    cout<<answer;
    return 0;
}