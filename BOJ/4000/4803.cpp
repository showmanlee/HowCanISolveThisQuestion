// 트리
// https://www.acmicpc.net/problem/4803

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int group[501];

int finding(int p) {
	if (p == group[p])
		return p;
	return group[p] = finding(group[p]);
}

void unioning(int a, int b) {
	int ga = finding(a);
	int gb = finding(b);
	if (ga > gb)
		group[ga] = gb;
	else if (gb > ga)
		group[gb] = ga;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int cases = 1;
	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		for (int i = 1; i <= n; i++)
			group[i] = i;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			if (finding(a) == finding(b)) {
				unioning(a, 0);
				unioning(b, 0);
			}
			else
				unioning(a, b);
		}
		set<int> cnt;
		for (int i = 1; i <= n; i++)
			finding(i);
		for (int i = 1; i <= n; i++)
			if (group[i] != 0)
				cnt.insert(group[i]);
		if (cnt.size() == 0)
			cout << "Case " << cases << ": No trees.\n";
		else if (cnt.size() == 1)
			cout << "Case " << cases << ": There is one tree.\n";
		else
			cout << "Case " << cases << ": A forest of " << cnt.size() << " trees.\n";
		cases++;
	}
}

// 그래프의 형태가 주어졌을 때, 해당 그래프에 몇 개의 트리가 있는지 확인하기

// 트리는 사이클이 없는 그래프 - union-find에서 두 노드를 이을 때, 이미 한 그룹 안에 들어가지 않은 경우 트리임이 보장됨
// 여기서 트리가 아니게 된 그래프가 등장한 경우 '트리가 없다'고 판정하지 말고, 해당 '그래프'를 뺀 나머지 노드 중 트리가 있는지 확인해야 함에 주의
// 만약 이미 트리를 이루고 있는 그래프를 다시 이을 경우 해당 트리는 그래프가 됨 - 0번 노드와 union하여 트리 개수 카운팅에서 배제
// 이후 모든 노드에 대해 find를 돌려주고, group 배열을 순회하면서 0번이 아닌 숫자가 등장한 횟수가 바로 트리의 개수 - set 활용
// 아무와도 이어지지 않은 노드 역시 하나의 트림임을 기억할 것