// Buffoon
// https://www.acmicpc.net/problem/17530

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int me;
	cin >> me;
	bool res = true;
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		if (p > me) {
			res = false;
		}
	}
	cout << (res ? "S" : "N") << '\n';
}

// 콘테스트에서 가장 많은 득표자, 또는 동률일 경우 가장 먼저 지원한 지원자가 승리할 때, 1번 지원자가 승리할 수 있는지 판정하기

// 1번 지원자의 득표수를 먼저 받고, 나중에 나오는 득표수 중 1번 지원자보다 높은 득표수가 나오는지 보기