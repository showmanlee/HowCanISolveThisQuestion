// Innohorse
// https://www.acmicpc.net/problem/21875

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	int x = abs(a[0] - b[0]), y = abs(a[1] - b[1]);
	if (x > y) {
		swap(x, y);
	}
	cout << x << ' ' << y << '\n';
}

// 체스말의 이동 경로가 주어질 때, 이동한 거리 구하기