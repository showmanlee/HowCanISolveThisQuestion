// 2021은 무엇이 특별할까?
// https://www.acmicpc.net/problem/24039

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> prime(10001, true);
	vector<int> pl;
	prime[0] = prime[1] = false;
	for (int i = 2; i <= 10000; i++) {
		if (prime[i]) {
			pl.push_back(i);
			for (int j = i * 2; j <= 10000; j += i)
				prime[j] = false;
		}
	}

	int n;
	cin >> n;
	for (int i = 0; i < pl.size() - 1; i++) {
		if (pl[i] * pl[i + 1] > n) {
			cout << (pl[i] * pl[i + 1]) << '\n';
			break;
		}
	}
}

// 주어진 수 보다 큰 연속된 소수 2개의 곱 중 가장 작은 수는?

// 조건이 명확하게 정해져 있기에 탐색 강도는 그렇게 높지 않음
// 에라토스테네스로 10000까지의 소수를 구한 뒤, 연속곱을 구하면서 주어진 수를 넘은 순간 해당 수 출력