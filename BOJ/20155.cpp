// 우리 집 밑에 편의점이 있는데
// https://www.acmicpc.net/problem/20155

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int res = 0;
	vector<int> count(m + 1);
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		count[p]++;
		if (res < count[p])
			res = count[p];
	}
	cout << res << '\n';
}

// m개의 브랜드를 가진 n개의 편의점에서 하루에 한 브랜드씩 잠복한다고 할 때, 몇 명이 필요한가?
// 브랜드 중 가장 많이 나온 수