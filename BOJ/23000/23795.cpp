// 사장님 도박은 재미로 하셔야 합니다
// https://www.acmicpc.net/problem/23795

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int res = 0;
	while (true) {
		int p;
		cin >> p;
		if (p == -1) {
			break;
		}
		res += p;
	}
	cout << res << '\n';
}

// 주어진 수 모두 더하기

// while true로 수를 계속 받아 더하다가 -1이 나오면 더하기 전에 나와서 결과 출력하기ㄴ