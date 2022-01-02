// 트리의 기둥과 가지
// https://www.acmicpc.net/problem/20924

#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pr;

int n, root, giga;
int resr, resl;
vector<pr> board[200001];
bool visit[200001];

void find_giga(int p) {
	if (giga != -1)
		return;
	visit[p] = true;
	int next = 0;
	int len = 0;
	int count = 0;
	for (pr r : board[p]) {
		if (!visit[r.first]) {
			count++;
			next = r.first;
			len = r.second;
		}
	}
	if (count != 1) {
		giga = p;
		return;
	}
	resr += len;
	find_giga(next);
}

void find_leaf(int p, int len) {
	visit[p] = true;
	int count = 0;
	for (pr r : board[p]) {
		if (!visit[r.first]) {
			count++;
			find_leaf(r.first, len + r.second);
		}
	}
	if (count == 0)
		resl = max(resl, len);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> root;
	giga = -1;
	resr = resl = 0;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a].push_back({ b, c });
		board[b].push_back({ a, c });
	}
	find_giga(root);
	find_leaf(giga, 0);
	cout << resr << ' ' << resl << '\n';
}

// 간선에 가중치가 있는 트리가 진짜 나무처럼 루트에서 시작한 한 줄의 기둥에서 여러 개의 가지로 뻗어나갈 때, 여러 개의 기둥으로 뻗기 시작하는 노드를 '기가 노드'라고 한다
// 이때 루트 노드에서 기가 노드까지의 길이(기둥의 길이)와 기가 노드에서 가장 멀리 떨어진 리프 노드의 길이(가장 긴 가지의 길이)는?

// 트리에서 길이를 구하라고 하니 dfs를 활용해야 함 - 다만 기둥 길이를 구하는 dfs(1)와 가지 길이를 구하는 dfs(2)를 별도로 만들기
// 루트 노드가 주어진 상태기 때문에 루트에서 기가까지는 (1), 기가에서 가지까지는 (2)를 사용해 순회한다
// 먼저 간선 입력받기 - 어디가 루트 쪽인지 명시되지 않기 때문에 일단 양방향으로 작성

// 이후 루트부터 (1)을 돌려 기가의 위치를 찾는다
// (1)에서는 탐색할 수 있는 노드가 1개인 동안 계속 그쪽 노드로 가면서 해당 노드로 가는 간선의 길이를 결과 1에 누적
// 만약 탐색할 수 있는 노드가 1개가 아닌 경우(가지가 없거나 갈라지기 시작한 곳), 해당 노드가 기가 노드가 됨

// 기가 노드를 구하면 기가 노드부터 (2)를 돌린다
// 여기서는 현재 노드와 더불어 지금까지의 길이를 매개변수로 받아 탐색할 수 있는 다음 노드가 발견되면 그쪽으로 분화되어 퍼질 수 있게 처리
// 즉, 일반적인 트리 dfs 기반으로 탐색
// 만약 탐색할 수 있는 노드가 없는 경우(가지의 끝), 지금가지 누적된 길이가 결과값보다 큰 경우 갱신, 이후 탈출
