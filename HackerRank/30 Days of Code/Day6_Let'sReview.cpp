// Day 6: Let's Review
// https://www.hackerrank.com/challenges/30-review-loop/problem

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j += 2)
            cout << s[j];
        cout << ' ';
        for (int j = 1; j < s.length(); j += 2)
            cout << s[j];
        cout << '\n';
    }   
    return 0;
}


// 1주차(입출력, 조건문, 반복문) 복습
// 문자열을 입력받고 짝수 번째 글자와 홀수 번째 글짜 따로 출력하기