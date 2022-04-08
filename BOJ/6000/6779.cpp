// Who Has Seen The Wind
// https://www.acmicpc.net/problem/6779

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int h, m;
	cin >> h >> m;
	int res = -1;
	for (int t = 1; t <= m; t++) {
		int a = (-6 * pow(t, 4)) + (h * pow(t, 3)) + (2 * pow(t, 2)) + t;
		if (a <= 0) {
			res = t;
			break;
		}
	}
	if (res == -1) {
		cout << "The balloon does not touch ground in the given time.\n";
	}
	else {
		cout << "The balloon first touches ground at hour: " << res << '\n';
	}
}

// 하늘로 날린 관측기가 t시간 후 −6t^4 + ht^3 + 2t^2 + t 고도에 있을 때, m 시간 안에 땅으로 떨어지는지 판정하기

// 4차함수이므로 하늘로 올라갔다 떨어지는 곡선을 가지고 있음
// 이를 참고하여 1부터 m까지 직접 계산해보면 됩니다