// Do Not Touch Anything
// https://www.acmicpc.net/problem/13136

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long r, c, n;
	cin >> r >> c >> n;
	long long rr = r / n + (r % n == 0 ? 0 : 1);
	long long cc = c / n + (c % n == 0 ? 0 : 1);
	cout << (rr * cc) << '\n';
}

// r * c 공간에 n * n 공간을 커버할 수 있는 CCTV를 놓을 때, 전체 공간을 커버하기 위해 필요한 수는?

// ceil(r / n) * ceil(c / n) - 이를 정수형에서 계산하기 위해 위의 방법으로 바꿀 수 있음
// 결과가 int 영역을 벗어날 수 있으므로 long long에서 계산