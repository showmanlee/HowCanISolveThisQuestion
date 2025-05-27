// 감소하는 수
// https://www.acmicpc.net/problem/1038

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;

void f(long long n) {
	v.push_back(n);
	if (n % 10 == 0) {
		return;
	}
	for (long long i = 0; i < n % 10; i++) {
		f(n * 10 + i);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (long long i = 0; i < 10; i++) {
		f(i);
	}
	sort(v.begin(), v.end());
	int n;
	cin >> n;
	if (n >= v.size()) {
		cout << -1 << '\n';
	} else {
		cout << v[n] << '\n';
	}
}

// 모든 자릿수가 내림차순인 음이 아닌 정수를 감소하는 수라 부를 때, n번째 감소하는 수 구하기