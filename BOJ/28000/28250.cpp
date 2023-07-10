// 이브, 프시케 그리고 푸른 MEX의 아내
// https://www.acmicpc.net/problem/28250

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
	long zero = 0, one = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] == 0) {
			zero++;
		} else if (v[i] == 1) {
			one++;
		}
	}
	long long res = 0;
	res += zero * one * 2;
	res += (zero * (zero - 1) / 2) + (zero * (n - one - zero));
	cout << res << '\n';
}

// mex(v)가 집합 v에 포함되지 않는 수 중 가장 작은 음이 아닌 정수로 정의될 때, n개의 수 중 2개를 뽑아 만든 mex({a, b})의 합은?

// v.size == 2라면 mex의 값은 3가지밖에 나올 수 없음 - 2(두 수가 0, 1일 때), 1(두 수 중 하나가 0일 때), 0(그 외 모든 경우)
// 따라서 (0, 1 조합 수) * 2 + (0, n(n != 1) 조합 수)를 구하면 됨