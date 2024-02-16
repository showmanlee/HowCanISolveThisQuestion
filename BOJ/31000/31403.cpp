// A + B - C
// https://www.acmicpc.net/problem/31403

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    cout << (a + b - c) << '\n';
    cout << (stoi(to_string(a) + to_string(b)) - c) << '\n';
}

// JavaScript에서 A + B - C을 정수로 봤을 때와 문자열로 봤을 때의 결과 출력하기

// 정수의 경우 진짜 저 수식이고, 문자열의 경우 A + B는 문자열 접합, - C는 수로 변환해서 뺀 값