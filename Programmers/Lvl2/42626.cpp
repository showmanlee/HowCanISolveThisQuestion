// 더 맵게
// https://programmers.co.kr/learn/courses/30/lessons/42626

#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);
    while(pq.top() < K){
        if (pq.size() == 1){
            answer = -1;
            break;
        }
        int a = pq.top();
        pq.pop();
        int b = a + pq.top() * 2;
        pq.pop();
        pq.push(b);
        answer++;
    }
    return answer;
}