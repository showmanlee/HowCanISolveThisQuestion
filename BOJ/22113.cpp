// 창영이와 버스
// https://www.acmicpc.net/problem/22113

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> order(m);
	for (int i = 0; i < m; i++)
		cin >> order[i];
	vector<vector<int>> costs(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> costs[i][j];
	int res = 0;
	for (int i = 1; i < m; i++)
		res += costs[order[i - 1]][order[i]];
	cout << res << '\n';
}

// 각 버스 간의 환승 요금표가 주어질 때, 주어진 순서대로 버스를 환승할 때 드는 비용 구하기

// 순서와 요금표를 받은 다음, 순서를 순회하며 앞뒤 두 개의 버스 번호를 활용, 환승 비용을 구해 더해서 출력하기