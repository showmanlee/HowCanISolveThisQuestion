// Positioning Peter’s Paintings
// https://www.acmicpc.net/problem/34466

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, x, y;
	cin >> a >> b >> x >> y;
	int res = min(max(a, x) + b + y, max(b, y) + a + x) * 2;
	cout << res << '\n';
}

// a*b, x*y 보드를 붙여서 전시하는데 드는 최소 둘레 출력하기