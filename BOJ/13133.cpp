// Aurora Princess
// https://www.acmicpc.net/problem/13133

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> bl(n + 1);
	vector<bool> gone(n + 1);
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		bl[a].push_back(i);
		bl[b].push_back(i);
		if (a == 0 || b == 0)
			gone[i] = true;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		gone[p] = true;
		for (int j : bl[p])
			gone[j] = true;
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		res += (gone[i] ? 0 : 1);
	cout << res << '\n';
}

// 어떤 사람의 부모 관계가 주어지고, 사라지는 사람이 주어졌을 때, 자신과 부모가 모두 사라지지 않은 사람(행복한 사람)의 수는?

// 일단 가족관계가 말도 안 되는 경우가 나올 수 있음 - 또한 초기 상태에서 부모가 없는 경우도 있을 수 있음
// 부모 한 명이 사라지면 그의 자식들이 모두 행복해지지 않게 됨 - 자신의 자식들을 2차원 vector에 트리 형태로 저장
// 그리고 각각의 행복 여부를 체크하는 배열을 만들고, 만약 입력된 부모 중 하나가 없다면 처음부터 행복하지 않음에 체크
// 이후 사라진 사람들을 받으며 그 사람을 부모로 가진 모든 사람을 행복하지 않게 설정
// 마지막으로 행복 배열을 순회하며 행복한 사람들을 세서 출력하기