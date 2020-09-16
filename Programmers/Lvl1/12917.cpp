// 문자열 내림차순으로 배치하기
// https://programmers.co.kr/learn/courses/30/lessons/12917

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    for (int i = 0; i < s.size(); i++){
        int max = i;
        for (int j = i; j < s.size(); j++){
            if (s[max] < s[j])
                max = j;
        }
        char temp = s[i];
        s[i] = s[max];
        s[max] = temp;
    }
    return s;
}