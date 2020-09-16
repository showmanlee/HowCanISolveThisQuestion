// 문자열을 정수로 만들기
// https://programmers.co.kr/learn/courses/30/lessons/12925

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool buho = true;
    for (int i = 0; i < s.size(); i++){
        if (s.at(i) == '-')
            buho = false;
        else if (s.at(i) == '+')
            buho = true;
        else{
            answer *= 10;
            answer += s.at(i) - '0';
        }
    }
    if (!buho)
        answer *= -1;
    return answer;
}