// 3진수 뒤집기
// https://programmers.co.kr/learn/courses/30/lessons/68935

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int make3(int n){
    string s = "";
    while(n > 0){
        s = (to_string(n % 3)) + s;
        n /= 3;
    }
    int res = 0, len = s.length();
    for (int i = 0; i < len; i++)
        res += (s[i] - '0') * pow(3, i);
    return res;
}

int solution(int n) {
    int answer = make3(n);
    return answer;
}

// 문자열을 앞에서부터 순회하면 반전한 것과 같음