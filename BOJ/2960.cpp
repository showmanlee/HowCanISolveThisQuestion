// 에라토스테네스의 체
// https://www.acmicpc.net/problem/2960

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	vector<bool> prime(n + 1);
	int min = 2, count = 0, res = 0;
	bool stop = false;
	while (true) {
		for (int i = min; i <= n; i += min) {
			if (!prime[i]) {
				count++;
				prime[i] = true;
			}
			if (count == k) {
				stop = true;
				res = i;
				break;
			}
		}
		if (stop)
			break;
		for (int i = 2; i <= n; i++)
			if (!prime[i]) {
				min = i;
				break;
			}
	}
	cout << res << '\n';
}

// 에라토스테네스의 체 방식으로 수를 순서대로 지워나갈 때 k번째로 지우는 수는?
// 1000까지니까 부담없이 지워나가면 된다