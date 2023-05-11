// 수찬은 마린보이야!!
// https://www.acmicpc.net/problem/15921

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << fixed;
    cout.precision(2);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if (n == 0) {
		cout << "divide by zero\n";
	} else {
		float abs = 0, exp = 0;
		for (int i = 0; i < n; i++) {
			abs += v[i];
			exp += v[i] * 1.0f / n;
		}
		abs /= n;
		if (exp == 0) {
			cout << "divide by zero\n";
		} else {
			cout << (abs / exp) << '\n';
		}
	}
}

// 배열의 크기와 값들이 주어질 때, 배열에 대한 평균/기댓값 구하기

// 기댓값 = 각 사건이 벌어졌을 때의 이득과 그 사건이 벌어질 확률을 곱한 것을 전체 사건에 대해 합한 값, 즉 값 * (그 값의 등장 확률)의 합
// 다르게 변형하면 값 / n의 합이라고 볼 수 있음 - 따라서 이 둘을 구하고 나눠주면 됨
// n이 0일 수 있음에 주의 - 또 배열 값으로 0이 등장하므로 0만 나올 경우 기댓값이 0이 될 수 있음에도 주의