#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T > 0) {
        int N, M;
        cin >> N >> M;

        vector<int> priority(N);
        // 인덱스,우선순위로 큐 관리
        // 큐 동작 구현 (top의 우선순위 보다 큰게 남았다면 )
        queue<pair<int, int>> printQ;
        for (int i = 0; i < N; i++) {
            cin >> priority[i];
            printQ.push({i, priority[i]});
        }

        // 큐를 복사하여 front의 우선순위보다 큰 우선순위를 가지는 요소가 있는지
        
		vector<int> order(N);
		int count=0;
        while (!printQ.empty()) {
			int idx= printQ.front().first;
            int front = printQ.front().second;
            bool exists = false;
			queue<pair<int, int>> copyQ = printQ;

            while (!copyQ.empty()) {
                if (copyQ.front().second > front) {
                    exists = true;
                    break;
                }
                copyQ.pop();
            }

			
			if(exists==true){
				printQ.pop();
				printQ.push({idx,front});
			}
			else{
				count++;
				order[idx]=count;
				printQ.pop();
			}
        }

		cout<<order[M]<<"\n";
        T--;
    }
    return 0;
}