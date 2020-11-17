// 기능개발
// https://programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> work;
    for (int i = 0; i < speeds.size(); i++){
        int p = 100 - progresses[i];
        if (p % speeds[i] == 0)
            p /= speeds[i];
        else
            p = p / speeds[i] + 1;
        work.push(p);
    }
    int last = work.front(), count = 1;
    work.pop();
    while(!work.empty()){
        int p = work.front();
        work.pop();
        if (last >= p)
            count++;
        else{
            answer.push_back(count);
            count = 1;
            last = p;
        }
    }
    if (count != 0)
        answer.push_back(count);
    return answer;
}

// 큐를 이용한 문제
// 작업 길이를 순서대로 큐에 담아 앞에 나온 것보다 짧으면 카운트만 올리고 긴 날짜가 나오면 지금까지 모은 카운트를 정답 칸에다 넣고 새로운 카운트를 시작한다