// 사과
// https://www.acmicpc.net/problem/10833

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
		int a, b;
		cin >> a >> b;
		res += b % a;
	}
	cout << res << '\n';
}

// a명으로 구성된 반에 b개의 사과를 똑같이 나눠줄 때, 남는 사과의 최소 개수는?

// b / a = p ... q에서 q를 찾는 문제
// 따라서 b % a를 모두 구해서 이를 모두 더해주면 정답