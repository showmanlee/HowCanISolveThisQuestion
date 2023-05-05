// 평균 중앙값 문제
// https://www.acmicpc.net/problem/5691

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) {
			break;
		}
		cout << (a * 2 - b) << '\n';
	}
}

// 주어진 두 수와 평균과 중앙값이 같은 다른 수 구하기

// 정답은 a * 2 - b -> 예제에 나온 대로...