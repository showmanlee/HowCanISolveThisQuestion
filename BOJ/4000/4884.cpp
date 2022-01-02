// FIFA 월드컵
// https://www.acmicpc.net/problem/4884

#include <iostream>
using namespace std;

int main(void) {
	while (true) {
		long long g, t, a, d;
		cin >> g >> t >> a >> d;
		if (g == -1)
			break;

		long long p = g * a + d;
		long long y = 1;
		while (y < p)
			y *= 2;
		long long x = y - 1;
		for (long long i = 1; i <= t - 1; i++)
			x += i * g;
		long long k = 2;
		y = y - p;

		cout << g << '*' << a << '/' << t << '+' << d << '=' << x << '+' << y << '\n';
	}
}

// 월드컵 조별리그에서 T개의 팀으로 이뤄진 그룹(G) 당 A팀이 진출하는데, 이번에 여기에 조별리그 면제 팀(D)을 추가하고자 한다
// 총 경기 수가 X, 참가팀을 n^2 꼴로 만들기 위해 필요한 팀의 수가 Y일 때, G*A/T+D=X+Y 구하기
// 입력 범위가 long long임에 주의