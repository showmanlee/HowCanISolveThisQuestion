// 문자열 내 마음대로 정렬하기
// https://programmers.co.kr/learn/courses/30/lessons/12915

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    for (int i = strings.size() - 1; i >= 1; i--){
        for (int j = 0; j < i; j++){
            if (strings[j][n] > strings[j + 1][n])
                swap(strings[j], strings[j+1]);
            else if (strings[j][n] == strings[j + 1][n]){
                if (strings[j].compare(strings[j + 1]) > 0)                
                    swap(strings[j], strings[j+1]);
            }
        }
    }
    answer = strings;
    return answer;
}
// 인덱스의 글자돌로 소팅, 사전순으로 같으면 진행.