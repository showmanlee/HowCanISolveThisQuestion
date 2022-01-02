// 텔레프라임
// https://www.acmicpc.net/problem/7789

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> prime(10000001, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sqrt(10000001); i++) {
		if (prime[i]) {
			for (int j = i * 2; j <= 10000000; j += i)
				prime[j] = false;
		}
	}
	int a, b;
	cin >> a >> b;
	bool res = prime[a] && prime[a + b * 1000000];
	cout << (res ? "Yes" : "No") << '\n';
}

// 주어진 여섯 자리 수와 그 앞에 주어진 수 한 자리가 더 붙은 수가 모두 소수인지 판정하기

// 6자리, 7자리 수의 소수 판별 문제 - 다행히 천만개의 에라토스테네스를 메모리가 받혀줌
// 따라서 이를 이용해 6자리와 7자리의 소수를 판별합시다
