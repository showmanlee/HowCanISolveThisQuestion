// 영화감독 숌
// https://www.acmicpc.net/problem/1436

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n, count = 0, title = 665;
	cin >> n;
	while (count != n) {
		title++;
		if (to_string(title).find("666") != -1)
			count++;
	}
	cout << title << endl;
}
// 무조건 x666 순으로 가지 않음(6660, 6661, 6662...)
// 걍 665부터 ++해가며 n으로 돌려도 됨 - 이게 브루트포스
// string.find - 문자열에서 부분문자열 찾기, 있으면 인덱스 없으면 -1