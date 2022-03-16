// 폭죽쇼
// https://www.acmicpc.net/problem/1773

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, c;
	cin >> n >> c;
	vector<int> time(n);
	for (int i = 0; i < n; i++) {
		cin >> time[i];
	}
	int res = 0;
	for (int i = 1; i <= c; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i % time[j] == 0) {
				cnt++;
			}
		}
		if (cnt > 0) {
			res++;
		}
	}
	cout << res << '\n';
}

// c초 동안 n명의 학생이 각자의 간격마다 폭죽을 쏠 때, 폭죽이 터지는 시간 세기

// 여러 개의 폭죽이 동시에 터져도 1번으로 세는 것에 주의
// 말인즉 나머지 연산으로 풀 수 있다는 것 - n*c로 돌아도 충분히 가능함