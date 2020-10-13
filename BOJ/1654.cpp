// 랜선 자르기
// https://www.acmicpc.net/problem/1654

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int k, n;
	long long min = 1, max = -1;
	long long res = -1;
	cin >> k >> n;
	vector<int> cable(k);
	for (int i = 0; i < k; i++) {
		cin >> cable[i];
		if (cable[i] > max)
			max = cable[i];
	}
	while (min <= max) {
		long long mid = (min + max) / 2, result = 0;
		for (int i = 0; i < k; i++)
			result += cable[i] / mid;

		if (result >= n) {
			min = mid + 1;
			if (mid > res)
				res = mid;
		}
		else
			max = mid - 1;
	}
	cout << res << '\n';
}
// 이분 탐색!
// min, max가 모두 2^31 - 1 값을 가질 수 있지만 mid에서 이를 더하고 나누는 과정에서 int로 커버 불가능해짐 -> long long으로 처리