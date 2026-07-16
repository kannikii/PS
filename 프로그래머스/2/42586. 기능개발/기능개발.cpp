#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    // 앞의 작업이 100이 되어야지 뒤의 작업이 배포가능 
    // 따라서 배포를 위한 준비 큐를 생성 
    // progresses 순서대로 우선 전부 준비 큐에 삽입
    // 각각의 값이 100이 되는 턴 계산
    // 준비 큐에 100되면 배포 준비 상태 표시
    // 큐가 빌때까지
    // 준비 상태가 on이면 FIFO로 dequeue
    // 계속 dequeue하다가 그만 dequeue하면 거기까지 count 한걸 answer에 추가
    // 위 반복
    
    vector<int> readyDate(progresses.size());
    queue<pair<int,bool>> readyQueue;
    // {progresses인덱스, 준비상태}
    // 일단 다 들어가있다가 준비상태에 따라 dequeue하도록 할지
    // 아니면 다른 방식을 생각해봐야하나
    // 먼가 답이 아닐거 같음
    // 그냥 준비되는 일자 readyDate까지는 기록 하고,
    // 이걸로 따로 큐로 나오게 하는 방식 생각해봐야하나
    for(int i=0;i<progresses.size();i++){
        readyQueue.push({i,false});
    }
    
    for(int i=0;i<progresses.size();i++){
        int j=0;
        while(true){
            progresses[i]+=speeds[i];
            j++;
            if(progresses[i]>=100){
                break;
            }
        }
        // j가 작업 100%되는 날짜이므로 기록해둠
        readyDate[i]=j;
        // ex: [5,10,1,1,20,1]
    }
    
    // readyDate를 이용해 배포 개수 계산
    int i = 0;

    while(i < readyDate.size()){

        int standardDay = readyDate[i]; // 현재 배포 기준 날짜
        int count = 1;                  // 현재 기능은 무조건 배포

        i++;

        while(i < readyDate.size() && readyDate[i] <= standardDay){
            count++;
            i++;
        }

        answer.push_back(count);
    }

    return answer;
}