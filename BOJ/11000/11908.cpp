// 카드
// https://www.acmicpc.net/problem/11908

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	int maxx = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		res += p;
		maxx = max(maxx, p);
	}
	res -= maxx;
	cout << res << '\n';
}

// 서로 다른 수와 무늬가 찍힌 n장의 카드 중 2장을 뽑아 더 작은 수를 취하고 큰 수는 다시 놓는 과정을 1장만 남을 때까지 반복할 때, 취할 수 있는 카드 수의 합의 최댓값은?

// 둘 중 작은 수만 취하는 과정을 반복하면 결국 가장 큰 수만 남게 된다
// 따라서 문제의 답 역시 모든 카드의 합에서 가장 큰 수를 뺀 것