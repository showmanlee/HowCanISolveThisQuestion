// 몇개고?
// https://www.acmicpc.net/problem/27294

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	if ((a >= 12 && a <= 16) && b == 0) {
		cout << 320 << '\n';
	} else {
		cout << 280 << '\n';
	}
}

// a가 12~16이고 b가 0일 때는 320, 그렇지 않다면 280 출력하기

// 