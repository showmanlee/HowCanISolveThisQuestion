// Copier
// https://www.acmicpc.net/problem/26574

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		cout << p << ' ' << p << '\n';
	}
}

// 입력받은 수를 두 번 출력하기

// 하면 됩니다