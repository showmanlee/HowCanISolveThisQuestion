// BFS 스페셜 저지
// https://www.acmicpc.net/problem/16940

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<int> board[100001];
int origin[100001];
int simulate[100001];
bool visit[100001];
int counter;

bool compare(int a, int b) {
	return origin[a] < origin[b];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
		board[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		origin[p] = i;
	}
	for (int i = 1; i <= n; i++)
		sort(board[i].begin(), board[i].end(), compare);

	counter = 1;
	queue<int> q;
	q.push(1);
	visit[1] = true;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		simulate[p] = counter++;
		for (int i : board[p]) {
			if (!visit[i]) {
				visit[i] = true;
				q.push(i);
			}
		}
	}
	int res = 1;
	for (int i = 1; i <= n; i++) {
		if (origin[i] != simulate[i]) {
			res = 0;
			break;
		}
	}
	cout << res << '\n';
}

// 트리와 BFS 순회 결과가 주어질 때, 유효한 BFS 순회인지 판정하기
// bfs 순회 순서를 받고, 우리도 bfs를 돌려보면서 맞는 순서인지 확인해야 함 - 해당 노드가 몇 번째로 등장했는지 확인하는 배열 생성
// 반드시 낮은 번호부터 순회한다는 보장이 없음 - 직접 시뮬레이션 하기 전 주어진 순회 결과에서 먼저 나온 순서대로 트리 정렬이 필요함
// 이후 bfs를 실제로 돌리면서 전역 변수를 활용해 순회 순서를 또다른 배열에 똑같이 기록하고, 이후 두 순서 배열을 비교하며 순서가 다른 노드가 나오면 탈락
// 저번에 풀었던 dfs 스페셜 저지와 원리는 똑같음 - dfs가 bfs로 바뀌었을 뿐