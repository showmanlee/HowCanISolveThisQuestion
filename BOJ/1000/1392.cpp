// 노래 악보
// https://www.acmicpc.net/problem/1392

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		v[i + 1] = v[i] + p;
	}
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		for (int j = 0; j < n; j++) {
			if (v[j] <= p && v[j + 1] > p) {
				cout << (j + 1) << '\n';
				break;
			}
		}
	}
}

// 순서대로 연주되는 악보의 길이가 주어질 때, 주어진 시각에 치고 있는 악보 구하기

// 악보의 길이를 순서대로 누적하여 배열에 저장하고, [j - 1] <= q < [j]를 찾는다