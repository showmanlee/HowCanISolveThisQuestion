// Day 0: Hello, World.
// https://www.hackerrank.com/challenges/30-hello-world/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string input_string; 
    getline(cin, input_string); 
    cout << "Hello, World." << endl;

    cout << input_string << endl;

    return 0;
}

// 2020년을 마무리하는 대규모(?) 프로젝트 - 30 Days of Code 클리어
// 이번에는 C++뿐만 아니라 Java, Python, C#으로도 동시에 풀어봅니다
// 오늘은 입력 문자열을 받아두었을 때, 이를 출력하기