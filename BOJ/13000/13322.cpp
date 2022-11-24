// 접두사 배열
// https://www.acmicpc.net/problem/13322

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		cout << i << '\n';
	}
}

// 어떤 문자열의 접두사 배열을 만들 때, 해당 배열을 정렬했을 때 접두사 끝점의 위치들 출력하기

// 접미사는 몰라도 접두사는 앞에서 가져운 글자 수에 따라 차례대로 정렬된다 - 이걸 발견하면 문자열 정렬을 돌릴 필요가 없음
// 극단적으로, 이 문제는 문자열을 받고 0부터 문자열 길이 - 1까지 for문으로 출력하는 문제...