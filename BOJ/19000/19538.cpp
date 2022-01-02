// 루머
// https://www.acmicpc.net/problem/19538

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> board(n + 1);
	vector<int> dim(n + 1);
	for (int i = 1; i <= n; i++) {
		while (true) {
			int p;
			cin >> p;
			if (p == 0)
				break;
			board[i].push_back(p);
			dim[i]++;
		}
	}
	int m;
	cin >> m;
	vector<int> res(n + 1, -1);
	vector<int> visit(n + 1);
	queue<pr> q;
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		res[p] = 0;
		q.push({ p, 1 });
		visit[p] = 1;
	}
	while (!q.empty()) {
		int p = q.front().first;
		int time = q.front().second;
		q.pop();
		for (int i : board[p]) {
			visit[i]++;
			if (res[i] == -1 && visit[i] >= dim[i] / 2.0) {
				res[i] = time;
				q.push({ i, time + 1 });
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << res[i] << ' ';
	cout << '\n';
}

// 사람들로 구성된 네트워크에서 내 주변 절반 이상의 사람이 루머를 믿을 때 자신도 루머를 믿게 된다고 한다. 루머 최초 유포자(들)이 주어질 때, 각각의 사람들이 루머를 믿게 되는 시점은?

// 기본적으로 bfs긴 하지만, 다음 노드 탐색 시점을 다르게 봐야 하는 bfs
// 네트워크 입력을 받으면서 주변인 수를 나타내는 dim 배열을 저장하고, visit 배열은 현재 자신 주변의 루머를 믿는 사람의 수를 기록하는 배열로 활용
// res 배열은 해당 인물이 루머를 믿게 된 시점을 기록한다
// 보드와 최초 유포자를 받은 뒤, 최초 유포자부터 탐색을 시작한다
// 큐 안에서는 해당 인물과 연관된 모든 인물의 visit를 1씩 올려주는데, 만약 이로 인해 루머를 믿지 않던 사람의 visit가 dim[i] / 2.0 이상이 될 때 루머를 믿게 하고 큐에 삽입한다
// 따라서 큐에 들어오는 모든 사람은 루머를 믿고 있는 사람임이 보장됨 - 같은 노드는 다시 탐색하지 않는 bfs 원칙에도 충족