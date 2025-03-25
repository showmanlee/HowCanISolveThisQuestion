// 바둑돌 게임
// https://www.acmicpc.net/problem/25592

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int cnt = 1;
	while (n >= cnt) {
		n -= cnt;
		cnt++;
	}
	if (cnt % 2 == 0) {
		cout << 0 << '\n';
	} else {
		cout << (cnt - n) << '\n';
	}
}

// 서로 n개의 돌을 하나씩 더 차례로 가져가는 게임에서 선공이 이기기 위해 추가해야 할 돌의 개수 구하기