// 이상한 문자 만들기
// https://programmers.co.kr/learn/courses/30/lessons/12930

#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            index = -1;
            answer += ' ';
        }
        else if (index % 2 == 0)
            answer += toupper(s[i]);
        else if (index % 2 == 1)
            answer += tolower(s[i]);
        index++;
    }
    return answer;
}