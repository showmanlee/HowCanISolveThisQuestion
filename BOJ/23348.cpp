// 스트릿 코딩 파이터
// https://www.acmicpc.net/problem/23348

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, n;
	cin >> a >> b >> c >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int p = 0;
		for (int j = 0; j < 3; j++) {
			int x, y, z;
			cin >> x >> y >> z;
			p += a * x + b * y + c * z;
		}
		res = max(res, p);
	}
	cout << res << '\n';
}

// 주어진 기술 3개를 시연할 때마다 각 기술에 해당하는 점수를 받을 수 있고, 3인 1조의 팀의 총점은 개인 점수의 총합일 때, 우승한 조의 점수는?

// 곱셈 + 덧셈 계산해봐요
// 최고 점수만 얻으면 되므로 배열을 만들 필요도 없습니다