#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> checkArr(4,0);
vector<int> myArr(4,0);
int checkSecret=0;
int result=0;

void Add(char c);
void Remove(char c);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S,P;
    cin>>S>>P;


    string A;
    cin>>A;


    for(int i=0;i<4;i++){
        cin>>checkArr[i];
        if(checkArr[i]==0){
            checkSecret++;
        }
    }
    
    for(int i=0;i<P;i++){
        Add(A[i]);
    }
    if(checkSecret==4){
            result++;
    }
    //i는 새로 들어오는 문자 위치를 나타냄 
    for(int i=P;i<S;i++){
        int j=i-P; //윈도우에서 빠져야할 문자 위치

        Add(A[i]);
        Remove(A[j]);
        if(checkSecret==4){
            result++;
        }
    }
    cout<<result<<"\n";
    
}

void Add(char c){
    switch (c)
    {
    case 'A':
        myArr[0]++;
        if(myArr[0]==checkArr[0]){
            checkSecret++;
        }
        break;
    case 'C':
        myArr[1]++;
        if(myArr[1]==checkArr[1]){
            checkSecret++;
        }
        break;
    case 'G':
        myArr[2]++;
        if(myArr[2]==checkArr[2]){
            checkSecret++;
        }
        break;
    case 'T':
        myArr[3]++;
        if(myArr[3]==checkArr[3]){
            checkSecret++;
        }
        break;
    }
}
void Remove(char c){
     switch (c)
    {
    case 'A':
        if(myArr[0]==checkArr[0]){
            checkSecret--;
        }
        myArr[0]--;
        break;
    case 'C':
        
        if(myArr[1]==checkArr[1]){
            checkSecret--;
        }
        myArr[1]--;
        break;
    case 'G':
        if(myArr[2]==checkArr[2]){
            checkSecret--;
        }
        myArr[2]--;
        break;
    case 'T':
        if(myArr[3]==checkArr[3]){
            checkSecret--;
        }
        myArr[3]--;
        break;
    }
}