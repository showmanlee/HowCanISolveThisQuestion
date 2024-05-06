// 정보보호학부 동아리 소개
// https://www.acmicpc.net/problem/28691

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    char c;
    cin >> c;
    if (c == 'M') {
        cout << "MatKor\n";
    }
    if (c == 'W') {
        cout << "WiCys\n";
    }
    if (c == 'C') {
        cout << "CyKor\n";
    }
    if (c == 'A') {
        cout << "AlKor\n";
    }
    if (c == '$') {
        cout << "$clear\n";
    }
}

// 입력된 문자에 맞춰 문자열 출력하기