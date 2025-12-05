// 사탕 나눠주기
// https://www.acmicpc.net/problem/34873

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n * 2), cnt(n * 2 + 1);
	bool res = true;
	for (int i = 0; i < n * 2; i++) {
		cin >> v[i];
		cnt[v[i]]++;
		if (cnt[v[i]] > 2) {
			res = false;
		}
	}
	cout << (res ? "Yes" : "No") << '\n';
}

// n*2개의 수가 주어질 때, 2명에게 똑같이 중복되지 않은 수를 전달할 수 있는지 구하기