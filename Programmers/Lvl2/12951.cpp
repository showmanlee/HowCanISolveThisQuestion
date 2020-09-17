// JadenCase 문자열 만들기
// https://programmers.co.kr/learn/courses/30/lessons/12951

#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    bool upper = true;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == ' '){
            answer += s[i];
            upper = true;
        }
        else if (upper){
            answer += toupper(s[i]);
            upper = false;
        }
        else
            answer += tolower(s[i]);
    }
    return answer;
}