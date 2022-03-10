// 중복을 없애자
// https://www.acmicpc.net/problem/4592

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
		int prev = 0;
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			if (p != prev) {
				cout << p << ' ';
				prev = p;
			}
		}
		cout << "$\n";
	}
}

// 주어진 수열의 연속을 제거하여 출력하기

// 수를 입력할 때마다 이전에 입력된 수를 체크하여 서로 다르면 출력하기
// 입력과 출력을 동시에 수행해도 됨 - 어차피 입력 버퍼와 출력 버퍼는 서로 다름
// 단순히 중복을 지우는 게 아님에 주의 - 1 2 3 3 2 3의 경우 1 2 3이 아닌 1 2 3 2 3을 출력해야 함