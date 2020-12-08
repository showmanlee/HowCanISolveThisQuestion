// 다리를 지나는 트럭
// https://programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pr;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int i = 0, t = 1, current = 0;
    queue<pr> bridge;
    while(i < truck_weights.size()){
        if (!bridge.empty() && bridge.front().second <= t){
            current -= bridge.front().first;
            bridge.pop();
        }
        if (current + truck_weights[i] <= weight){
            bridge.push({truck_weights[i], t + bridge_length});
            current += truck_weights[i];
            i++;
        }
        t++;
    }
    while(!bridge.empty()){
        answer = bridge.front().second;
        bridge.pop();
    }
    return answer;
}

// 하중 제한이 있는 1차선 다리를 트럭들이 지나갈 때 걸리는 시간
// 큐 문제 - 트럭 무게와 나오는 시간을 pair로 만들어 활용해보자
// 시간은 1부터 시작함에 주의