// 문자열 내 p와 y의 개수
// https://programmers.co.kr/learn/courses/30/lessons/12916

#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p = 0, y = 0;
    for (int i = 0; i < s.size(); i++){
        if (s.at(i) == 'p' || s.at(i) == 'P')
            p++;
        if (s.at(i) == 'y' || s.at(i) == 'Y')
            y++;
    }
    answer = p == y;

    return answer;
}