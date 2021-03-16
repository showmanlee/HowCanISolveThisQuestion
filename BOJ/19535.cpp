// ㄷㄷㄷㅈ
// https://www.acmicpc.net/problem/19535

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<int> board[300001];
long long d, g;

long long combi(long long n) {
	long long ret = n * (n - 1) * (n - 2);
	return (ret / 6);
}

void bfsd() {
	for (int i = 1; i <= n; i++) {
		for (int j : board[i]) {
			if (j > i) {
				d += (board[i].size() - 1ll) * (board[j].size() - 1ll);
			}
		}
	}
}

void bfsg() {
	for (int i = 1; i <= n; i++) {
		if (board[i].size() >= 3)
			g += combi(board[i].size());
	}
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
	d = g = 0;
	bfsd();
	bfsg();
	if (d == g * 3)
		cout << "DUDUDUNGA\n";
	else if (d > g * 3)
		cout << "D\n";
	else
		cout << "G\n";
}

// 트리가 주어질 때, 4개의 노드를 가진 서브 트리 중 ㄷ형, ㅈ형의 개수로 D/G/DUDUDUNGA (ㄷ의 수가 ㅈ의 3배보다 많은지 적은지 같은지) 판정하기
// ㅈ는 노드들을 순회하면서 3개 이상의 노드와 연결된 노드를 봤을 때 (연결된 노드)C3 추가하기
// ㄷ는 노드 쌍들을 순회하면서 (왼쪽 노드와 연결된 노드 - 1) * (오른쪽 노드와 연결된 노드 - 1) 추가하기
// 그러니까 정석적인 트리 순회 문제는 아님
// 30만 개에 nC3 연산을 하려고 하니 long long을 베이스로 계산