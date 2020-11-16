// 이중우선순위큐
// https://programmers.co.kr/learn/courses/30/lessons/42628

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    
    for (string s : operations){
        char op = s[0];
        int num = stoi(s.substr(2));
        if (op == 'I'){
            dq.push_back(num);
            sort(dq.begin(), dq.end());
        }
        else if (op == 'D' && !dq.empty()){
            if (num == 1)
                dq.pop_back();
            else
                dq.pop_front();
        }
    }
    if (dq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    return answer;
}

// 새로운 자료구조나 2개의 힙을 만들지 않아도 deque를 삽입 시 정렬하는 선에서 해결 가능
// deque - 앞뒤로 데이터를 넣고 뺄 수 있는 큐(push_front(), push_back(), pop_front(), pop_back(), front(), back())
// 2개의 힙을 사용하는 버전은 BOJ 버전에서