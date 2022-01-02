// 주사위 게임
// https://www.acmicpc.net/problem/2476

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		int p = max(a, max(b, c)) * 100;
		if (a == b && b == c)
			p = 10000 + a * 1000;
		else if (a == b || a == c)
			p = 1000 + a * 100;
		else if (b == c)
			p = 1000 + b * 100;
		res = max(res, p);
	}
	cout << res << '\n';
}

// 세 개의 주사위를 굴려 다음과 같이 점수를 얻을 때, 가장 많은 점수를 얻은 사람의 점수는?
// 세 개가 모두 같은 경우 - 10000 + 눈 * 1000
// 두 개가 같은 경우 - 1000 + 같은눈 * 100
// 모두 다른 경우 - 큰눈 * 100

// 그저 결과를 내보면 됨