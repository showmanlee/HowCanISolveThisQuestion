// 공약수
// https://www.acmicpc.net/problem/5618

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int key = 987654321;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		key = min(key, v[i]);
	}
	for (int i = 1; i <= key; i++) {
		int pass = true;
		for (int j = 0; j < n; j++) {
			if (v[j] % i != 0) {
				pass = false;
				break;
			}
		}
		if (pass) {
			cout << i << '\n';
		}
	}
}

// 주어진 수들의 공약수들 구하기

// 모두 대입해보면 된다 - 주어진 수(2~3개)와 모두 나누어떨어지는 수
// 범위는 1부터 주어진 수 중 가장 작은 수까지