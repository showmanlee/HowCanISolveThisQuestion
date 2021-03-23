// 윷놀이
// https://www.acmicpc.net/problem/2490

#include <iostream>
using namespace std;

int main(void) {
	for (int t = 0; t < 3; t++) {
		int res = 0, p;
		for (int i = 0; i < 4; i++) {
			cin >> p;
			res += (p == 0 ? 1 : 0);
		}
		cout << char(res == 0 ? 'E' : 'A' + res - 1) << '\n';
	}
}

// 윷을 3번 던질 때, 각각의 상황에 대한 결과(도개걸윷모 - ABCDE) 출력하기
// 1이 앞(등), 0이 뒤(배)임에 주의