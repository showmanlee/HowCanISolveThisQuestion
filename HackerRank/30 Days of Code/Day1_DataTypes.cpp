// Day 1: Data Types
// https://www.hackerrank.com/challenges/30-data-types/problem

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    int j;
    double e;
    string t;
    cin >> j >> e;
    cin.get();
    getline(cin, t);
    cout << (i + j) << endl;
    cout << fixed << setprecision(1) << (d + e) << endl;
    cout << s << t << endl;

    return 0;
}

// 정수형, 실수형, 문자열을 입력받고 미리 만들어진 변수와 더하기/붙이기
// 실수형 출력 정확도 설정은 setprecision(자릿수), 여기서 fixed를 앞에 붙이면 실수부 자릿수만 보지만 안 붙이면 정수 영역까지 본다(반올림).
// cin으로 받고 바로 getline으로 받기 위해서는 cin.get()으로 플러싱 필요