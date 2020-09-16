// 시저 암호
// https://programmers.co.kr/learn/courses/30/lessons/12926

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.size(); i++){
        char c = s.at(i);
        if (s.at(i) >= 'a' && s.at(i) <= 'z'){
            if (c + n > 'z')
                c += n - 26;
            else
                c += n;
        }
        else if (s.at(i) >= 'A' && s.at(i) <= 'Z'){
            if (c + n > 'Z')
                c += n - 26;
            else
                c += n;
        }
        answer += c;
    }
    return answer;
}