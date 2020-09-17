// 짝지어 제거하기
// https://programmers.co.kr/learn/courses/30/lessons/12973

#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> t;
    t.push(s[0]);
    for (int i = 1; i < s.size(); i++){
        if (!t.empty() && s[i] == t.top())
            t.pop();
        else
            t.push(s[i]);
    }
    answer = t.empty() ? 1 : 0;
    return answer;
}