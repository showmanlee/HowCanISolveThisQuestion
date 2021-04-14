// 연길이의 이상형
// https://www.acmicpc.net/problem/20540

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	cout << (s[0] == 'I' ? 'E' : 'I') << (s[1] == 'N' ? 'S' : 'N') << (s[2] == 'F' ? 'T' : 'F') << (s[3] == 'P' ? 'J' : 'P') << '\n';
}

// MBTI가 주어졌을 때, 정확히 반대되는 MBTI 출력하기
// INFP - ESTJ