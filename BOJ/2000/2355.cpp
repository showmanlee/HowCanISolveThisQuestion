// 시그마
// https://www.acmicpc.net/problem/2355

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long a, b;
	cin >> a >> b;
	if (a > b)
		swap(a, b);
	cout << ((a + b) * (b - a + 1) / 2) << '\n';
}

// a에서 b까지 모두 더한 합은?

// a와 b가 전체 int 범위 안에 있으므로 for로는 못 풀지 - 하지만 우리는 연속된 수의 합 구하는 공식을 이미 알고 있지(feat. 가우스)
// a < b일 때, (a + b) * (b - a + 1) / 2 - a + b를 a와 b 사이에 있는 수 / 2만큼 곱한 값