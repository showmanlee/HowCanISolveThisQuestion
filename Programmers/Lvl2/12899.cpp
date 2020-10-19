// 124 나라의 숫자
// https://programmers.co.kr/learn/courses/30/lessons/12899

#include <string>
#include <vector>

using namespace std;

string make3(int n){
    string s = "";
    while(n > 0){
        if (n % 3 == 0)
            s = "4" + s;
        else
            s = to_string(n % 3) + s;
        n = n / 3 - (n % 3 == 0 ? 1 : 0);
    }
    return s;
}

string solution(int n) {
    string answer = make3(n);
    return answer;
}

// 3진수지만, 0이 관념적으로만 존재함
// 1 2 4  11 12 14 21 22 24  41  42  44  111 112 114...
// 1 2 10 11 12 20 21 22 100 101 102 110 111 112 120...
// 비밀은 0이 들어가는 상황에서 4를 넣고 n / 3 - 1을 해주는 것