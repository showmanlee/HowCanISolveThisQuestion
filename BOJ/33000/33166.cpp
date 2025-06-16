// 鉄道旅行 3 (Railway Trip 3)
// https://www.acmicpc.net/problem/33166

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int p, q, a, b;
	cin >> p >> q >> a >> b;
	int res = min(p, q) * a + max(q - p, 0) * b;
	cout << res << '\n';
}

// p km까지의 기본료가 a, 그 이상이 b일 때, q km 이동 운임 구하기