#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, float> m;

int main() {
    m["A+"] = 4.5;
    m["A0"] = 4.0;
    m["B+"] = 3.5;
    m["B0"] = 3.0;
    m["C+"] = 2.5;
    m["C0"] = 2.0;
    m["D+"] = 1.5;
    m["D0"] = 1.0;
    m["F"] = 0.0;

    string Subject[20] = {};
    float Credit[20] = {};
    float Grade[20] = {};

    string gradeStr;
    
    for (int i = 0; i < 20; i++) {
        cin >> Subject[i] >> Credit[i] >>gradeStr;
        if(gradeStr == "P"){
            Credit[i]=0;
            
        }else{
            Grade[i]=m[gradeStr];
        }
    }
    float sum=0.0;
    float sumCredit=0.0;
    for(int i=0;i<20;i++){
        sum+=Credit[i]*Grade[i];
        sumCredit+=Credit[i];
    }

    cout<<(float)(sum/sumCredit)<<"\n";
}