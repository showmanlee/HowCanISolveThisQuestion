// SUAPC 의자 준비하기
// https://www.acmicpc.net/problem/34183

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int p = (n * 3) - m;
	int res = 0;
	if (p > 0) {
		res = a * p + b;
	}
	cout << res << '\n';
}

// n개의 팀에게 각각 의자 3개씩을 주는데, 현재 의자가 m개 있고 추가로 사려면 개당 a원과 배송료 b원이 필요할 때, 의자를 보충하는데 드는 비용 구하기