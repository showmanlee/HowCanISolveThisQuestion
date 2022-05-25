// 掛け算 (Multiplication)
// https://www.acmicpc.net/problem/24421

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int res = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (v[i] * v[j] == v[k]) {
					res++;
				}
			}
		}
	}
	cout << res << '\n';
}

// 주어진 정수 배열에서 3개의 수를 뽑았을 때 순서대로 a * b = c가 되는 쌍의 수 구하기

// 실제로 하나씩 뽑아보면 된다 - 충분히 가능함
// 순서는 섞지 않고 그대로 유지함에 주의