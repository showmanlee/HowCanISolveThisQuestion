// A Game Called Mind
// https://www.acmicpc.net/problem/25850

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, char> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pr> v;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int p;
			cin >> p;
			v.push_back({p, 'A' + i});
		}
	}
	sort(v.begin(), v.end(), [](pr a, pr b) {
		return a.first < b.first;
	});
	for (pr p : v) {
		cout << p.second;
	}
	cout << '\n';
}

// n명이 낸 숫자카드가 주어질 떄, 낸 숫자카드들을 오름차순으로 정렬했을 때 카드 주인 차례로 출력하기