// Сравнение комнат
// https://www.acmicpc.net/problem/27267

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a * b > c * d) {
		cout << "M\n";
	} else if (a * b < c * d) {
		cout << "P\n";
	} else {
		cout << "E\n";
	}
}

// a * b, c * d 중 뭐가 큰지 판정하기

// 합니다