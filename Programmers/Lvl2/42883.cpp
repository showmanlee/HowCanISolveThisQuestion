// 큰 수 만들기
// https://programmers.co.kr/learn/courses/30/lessons/42883

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for (int i = number.size() - k; i > 0; i--){
        string temp = number.substr(0, number.size() - i + 1);
        int max = 0;
        for (int j = 1; j < temp.size(); j++)
            if (temp[max] < temp[j])
                max = j;
        answer += temp[max];
        number = number.substr(max + 1, number.size() - max);
    }
    return answer;
}