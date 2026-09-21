#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int x1[100], x2[100];

int main() {
    cin >> n;
    vector<int> v(100,0);
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        for(int j=x1[i];j<=x2[i];j++){
            v[j]++;
        }
    }

    // Please write your code here.
    cout<<*max_element(v.begin(),v.end());
    return 0;
}