// INU 순열
// https://www.acmicpc.net/problem/34555

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int p = (n + 1) / 2;
	cout << p << ' ';
	for (int i = 1; i < n; i++) {
		p += i * (i % 2 == 1 ? 1 : -1);
		cout << p << ' ';
	}
	cout << '\n';
}

// 어떤 항과 이전 항의 차의 절댓깂이 늘어나는 형태의 순열 만들기