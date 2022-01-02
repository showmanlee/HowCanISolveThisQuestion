// 음악프로그램
// https://www.acmicpc.net/problem/2623

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> tree(n + 1);
	vector<int> dim(n + 1);
	for (int t = 0; t < m; t++) {
		int p;
		cin >> p;
		int prev = -1;
		for (int i = 0; i < p; i++) {
			int z;
			cin >> z;
			if (prev != -1) {
				tree[prev].push_back(z);
				dim[z]++;
			}
			prev = z;
		}
	}
	queue<int> q;
	vector<int> res;
	vector<bool> visit(n + 1);
	for (int i = 1; i <= n; i++) {
		if (dim[i] == 0) {
			q.push(i);
			visit[i] = true;
		}
	}
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		res.push_back(p);
		for (int i : tree[p]) {
			dim[i]--;
			if (dim[i] == 0 && !visit[i]) {
				visit[i] = true;
				q.push(i);
			}
		}
	}
	if (res.size() != n)
		cout << 0 << '\n';
	else
		for (int i : res)
			cout << i << '\n';
}

// 음악 프로그램에서 여러 명의 pd들이 서로 다른 출연 순서를 가져왔을 때, 이를 취합하여 한 번에 표현할 수 있는가? 있다면 아무거나 출력하라
// 위상정렬 문제 - 이번에는 테크트리가 한 줄씩 주어짐
// 각 pd가 준 트리들에서 선행 가수가 있는 경우 해당 가수의 dim을 ++해주고, 선행 가수에게 후행 가수를 저장해준다
// 그렇다면 자연스럽게 출연 순서가 출연 트리가 됨
// 이후 dim이 0인 출연자부터 결과 배열에 삽입해주는데, 그렇게 돌린 결과 결과 배열의 크기가 가수의 수보다 적으면 에러