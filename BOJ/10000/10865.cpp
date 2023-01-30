// 친구 친구
// https://www.acmicpc.net/problem/10865

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> res(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		res[a]++;
		res[b]++;
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i] << '\n';
	}
}

// n명의 친구 관계가 주어질 때, 각각의 친구 수 구하기

// 중복된 관계가 주어지지 않음이 보장되므로 각자 등장한 만큼 세어서 출력하기