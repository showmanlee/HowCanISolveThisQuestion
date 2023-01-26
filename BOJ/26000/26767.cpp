// Hurra!
// https://www.acmicpc.net/problem/26767

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i % 7 == 0) {
			if (i % 11 == 0) {
				cout << "Wiwat!";
			} else {
				cout << "Hurra!";
			}
		} else if (i % 11 == 0) {
			cout << "Super!";
		} else {
			cout << i;
		}
		cout << '\n';
	}
}

// 7의 배수일 때 Wiwat, 11의 배수일 때 Super, 7과 11 모두의 배수일 때 Hurra를 외치는 게임에서 1부터 n까지의 게임 결과 출력하기

// 배수 확인해서 그대로 출력하는 게임 - 길긴 합니다