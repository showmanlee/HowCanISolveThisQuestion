// Triangles
// https://www.acmicpc.net/problem/7595

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				cout << '*';
			}
			cout << '\n';
		}
	}
}

// 0이 나올 때까지 주어진 수의 길이를 가진 삼각형 별 찍기

// while(true)가 가미된 일반적인 별 찍기 문제