// 다항함수의 미분
// https://www.acmicpc.net/problem/15725

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	if (s.find('x') == 0) {
		cout << 1 << '\n';
	}
	if (s.find('x') == 1 && s[0] == '-') {
		cout << -1 << '\n';
	}
	else if (s.find('x') == string::npos) {
		cout << 0 << '\n';
	}
	else {
		cout << s.substr(0, s.find('x')) << '\n';
	}
}

// 일차함수 미분하기

// 일차함수를 미분하면 x항의 계수만 남는다 - x의 위치를 보고 출력할 수를 판단한다
// 여기서는 항의 순서가 정해진 상태 - 즉 기본적으로 x의 위치가 확정되면 그 앞의 글자들이 x의 계수임이 보장되고, 이를 따서 출력하면 됨
// x가 등장하지 않는다면 상수항만 있는 것이므로 미분하면 0이 됨
// x의 계수 절댓값이 1이라면 1이 생략되므로 x가 맨 처음으로 등장하면 1을 출력하고, - 다음에 바로 x가 등장할 경우 -1 출력