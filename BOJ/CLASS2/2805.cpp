// 나무 자르기
// https://www.acmicpc.net/problem/2805

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	long long min = 0, max = 0, mid = 0, res = 0;
	vector<long long> trees(n);
	for (int i = 0; i < n; i++) {
		cin >> trees[i];
		if (max < trees[i])
			max = trees[i];
	}

	while (min <= max) {
		mid = (min + max) / 2;
		long long p = 0;
		for (long long i : trees)
			if (i - mid > 0)
				p += i - mid;

		if (p >= m) {
			if (res < mid)
				res = mid;
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
	}

	cout << res << '\n';
}

// 여러 개의 나무를 절단기로 일정한 높이에서 잘라서 가져갈 때, m미터의 나무를 가져가기 위해 설정할 수 있는 절단기의 최대 높이는?
// 이분 탐색 문제
// 절단기를 높일수록 나무 수는 줄어든다 - 정확한 값을 찾을 수 있는 순간은 하나 뿐, 최대한 높은 값을 찾아야 한다