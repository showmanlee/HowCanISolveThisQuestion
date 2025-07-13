// Practice: Roll Call
// https://www.acmicpc.net/problem/9306

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string a, b;
		cin >> a >> b;
		cout << "Case " << i << ": " << b << ", " << a << '\n';
	}
}

// 이름과 성이 주어질 때, 성, 이름으로 출력하기