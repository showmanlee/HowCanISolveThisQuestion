// 태보태보 총난타
// https://www.acmicpc.net/problem/17249

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int left = 0, right = 0;
	bool side = false;
	for (char c : s) {
		if (c == '@') {
			if (side)
				right++;
			else
				left++;
		}
		if (c == '(')
			side = true;
	}
	cout << left << ' ' << right << '\n';
}

// (^0^)가 양쪽으로 잔상과 함께 주먹(@)을 내지를 때, 내지른 주먹의 개수 구하기

// 입력된 문자열을 차례로 순회하며 @를 만나면 해당 방향의 주먹 개수 늘리기
// 만약 ((얼굴 시작)을 만났다면 방향 전환
// 이렇게 얻은 양쪽의 개수 출력하기