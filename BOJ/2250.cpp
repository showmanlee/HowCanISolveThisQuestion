// 트리의 높이와 너비
// https://www.acmicpc.net/problem/2250

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

pr node[10001];
pr level[10001];
int idx;

void dfs(int p, int l) {
	if (p == -1)
		return;
	dfs(node[p].first, l + 1);
	idx++;
	level[l].first = min(level[l].first, idx);
	level[l].second = max(level[l].second, idx);
	dfs(node[p].second, l + 1);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> cnt(n + 1);
	for (int i = 1; i <= n; i++) {
		level[i].first = 987654321;
		level[i].second = -987654321;
		int a, b, c;
		cin >> a >> b >> c;
		node[a] = { b, c };
		cnt[a]++;
		if (b != -1)
			cnt[b]++;
		if (c != -1)
			cnt[c]++;
	}
	int root = 0;
	for (int i = 1; i <= n; i++)
		if (cnt[i] == 1)
			root = i;
	idx = 0;
	dfs(root, 1);
	int resi = 0, resn = 0;
	for (int i = 1; i <= n; i++) {
		if (level[i].first == 987654321)
			break;
		int r = level[i].second - level[i].first + 1;
		if (resn < r) {
			resi = i;
			resn = r;
		}
	}
	cout << resi << ' ' << resn << '\n';
}

// 어떤 트리를 트리의 레벨을 행, 중위 순회한 순서를 열로 보며 표에 넣을 때, 너비가 가장 넓은 행 번호는?

// dfs 기반으로 중위 순회를 돌아주며 레벨(행)과 순서(열)을 구해주고, 이를 이용해 답을 얻어낸다 - 이를 위해 전역 배열로 각 노드 정보와 레벨의 최소/최대 열 번호 필요하고, 전역 변수로 순서값 필요
// 우선 트리 받기 - 노드 번호는 1~n이지만 루트가 1임은 보장되지 않으므로, 노드의 등장 횟수를 세어 자식 노드로 등장하지 않는 노드를 찾아 해당 노드를 루트화함
// 이후 dfs 중위 순회로 루트부터 순회 시작 - 자기 차례가 오면 순서값을 늘려준 후, 그 순서값(열번호)를 이용해 현재 레벨의 최대/최소 열 번호 갱신
// 마지막으로 기록된 모든 열을 순회하며 가장 넓은 너비를 찾아낸 후 출력하기