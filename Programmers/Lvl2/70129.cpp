// 이진 변환 반복하기
// https://programmers.co.kr/learn/courses/30/lessons/70129

#include <string>
#include <vector>

using namespace std;

string make2(int n){
    string res = "";
    while(n > 0){
        res = to_string(n % 2) + res;
        n /= 2;
    }
    return res;
}

vector<int> solution(string s) {
    vector<int> answer(2);
    while(s != "1"){
        int count = 0;
        for (char c : s)
            if (c == '0')
                count++;
        answer[1] += count;
        s = make2(s.length() - count);
        answer[0]++;
    }
    return answer;
}

// 문자열 x의 모든 0을 지우고, 그 *길이*를 이진법으로 만들어서 반복한다
// 따라서 오버플로 걱정은 없음