// 상근이의 친구들
// https://www.acmicpc.net/problem/5717

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int a, b;
		cin >> a >> b;
		int res = a + b;
		if (res == 0)
			break;
		cout << res << '\n';
	}
}

// 자신의 남자 친구 수와 여자 친구 수가 주어졌을 때, 전체 친구 수 구하기
// 남자면서 여자인 친구는 없으니, 단순히 덧셈이 됨