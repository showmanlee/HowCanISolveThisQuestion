// 주사위 네개
// https://www.acmicpc.net/problem/2484

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
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int p = 0;
		if (a == b && b == c && c == d)
			p = 50000 + a * 5000;
		else if ((a == b && b == c) || (a == b && b == d) || (a == c && c == d))
			p = 10000 + a * 1000;
		else if (b == c && c == d)
			p = 10000 + b * 1000;
		else if (a == b && c == d)
			p = 2000 + a * 500 + c * 500;
		else if ((a == c && b == d) || (a == d && b == c))
			p = 2000 + a * 500 + b * 500;
		else if (a == b || a == c || a == d)
			p = 1000 + a * 100;
		else if (b == c || b == d)
			p = 1000 + b * 100;
		else if (c == d)
			p = 1000 + c * 100;
		else
			p = max(a, max(b, max(c, d))) * 100;
		res = max(res, p);
	}
	cout << res << '\n';
}

// 네 개의 주사위를 굴려 다음과 같이 점수를 얻을 때, 가장 많은 점수를 얻은 사람의 점수는?
// 네 개가 모두 같은 경우 - 50000 + 눈 * 5000
// 세 개가 같은 경우 - 10000 + 같은눈 * 1000
// 두 개가 같은 게 2개 나온 경우 - 2000 + 같은눈1 * 500 + 같은눈2 * 500
// 두 개가 같은 경우 - 1000 + 같은눈 * 100
// 모두 다른 경우 - 큰눈 * 100

// 그저 결과를 내보면 됨(세개에 이어 다시)
// 조금 멍청이 같아보이긴 해도