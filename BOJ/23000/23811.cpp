// 골뱅이 찍기 - ㅌ
// https://www.acmicpc.net/problem/23811

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n * 5; i++) {
		for (int j = 0; j < n * 5; j++) {
			if (i / n == 0 || i / n == 2 || i / n == 4 || j / n == 0) {
				cout << '@';
			}
		}
		cout << '\n';
	}
}

// 획 두께가 n인 5*n 크기의 ㅌ 그리기

// 저번에 F 찍었을 때처럼 만들기