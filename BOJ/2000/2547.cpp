// 사탕 선생 고창영
// https://www.acmicpc.net/problem/2547

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		long long n;
		cin >> n;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			long long p;
			cin >> p;
			sum = (sum + p) % n;
		}
		cout << (sum == 0 ? "YES" : "NO") << '\n';
	}
}

// 학생들이 가져온 사탕을 모두 모아 학생들에게 똑같이 나눠줄 수 있는가?

// 사탕 수를 모두 더해 학생 수와 나누어떨어지는지 확인하기
// 다만 합이 long long 범위를 벗어날 수 있기에 하나 더할 때마다 mod 연산을 해줘야 함