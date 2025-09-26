// MIT Time
// https://www.acmicpc.net/problem/34459

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		int k = 5, res = 1;
		while (p > k) {
			k *= 5;
			res++;
		}
		cout << "MIT" << (res == 1 ? "" : "^" + to_string(res)) << " time\n";
	}
}

// 주어진 수가 5의 몇승 이하인지 출력하기 