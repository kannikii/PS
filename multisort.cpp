#include <iostream>
#include <algorithm>
using namespace std;

struct Score {
    int english,math;
    bool operator<(const Score& other) const {
        if(math !=other.math)
            return math<other.math;
        return english<other.english;
    }
};

bool compare(const Score& a, const Score& b) {
    if(a.english!=b.english){
        return a.english>b.english;
    }
    return a.math>b.math;
}


int main() {
    Score score[] = {
        {80,100},
        {100,50},
        {70,100},
        {80,90}
    };
    int n = sizeof(score)/sizeof(score[0]);
    sort(score,score+n);

    for(int i =0;i<n; ++i){
        cout<<"ENGLISH:" << score[i].english<< " MATH:"<<score[i].math<<'\n';
    }
}