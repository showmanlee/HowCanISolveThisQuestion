// 문자열 다루기 기본
// https://programmers.co.kr/learn/courses/30/lessons/12918

#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if (s.length() != 4 && s.length() != 6)
        return false;
    for (int i = 0; i < s.length(); i++)
        if (s[i] < '0' || s[i] > '9')
            return false;
    return true;
}

// 숫자로만 구성되어 있고, 길이가 4/6인가?