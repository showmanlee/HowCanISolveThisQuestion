// 사다리 조작
// https://www.acmicpc.net/problem/15684

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, h;
bool board[12][31];
int res;

void dfs(int p, int t) {
	if (res != 987654321)
		return;
	if (p == 0) {
		bool pass = true;
		for (int i = 1; i <= n; i++) {
			int cur = i;
			for (int j = 1; j <= h; j++) {
				if (board[cur][j])
					cur++;
				else if (board[cur - 1][j])
					cur--;
			}
			if (cur != i) {
				pass = false;
				break;
			}
		}
		if (pass)
			res = min(res, p);
		return;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = t; j <= h; j++) {
			if (board[i][j] || board[i - 1][j] || board[i + 1][j])
				continue;
			board[i][j] = true;
			dfs(p - 1, j);
			board[i][j] = false;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		board[b][a] = true;
	}
	res = 987654321;
	for (int i = 0; i <= 3; i++) {
		dfs(i, 0);
		if (res != 987654321) {
			res = i;
			break;
		}
	}
	if (res == 987654321)
		res = -1;
	cout << res << '\n';
}

// n개의 세로줄 사이 h개의 가로줄을 그을 수 있는 사다리에서 i번째 출발점의 결과가 i번째 도착점으로 만들기 위해 그어야 하는 가로줄(max 3) 개수는?

// 무작정(?) 보드에 줄을 그어봐야 함 - dfs 기반으로!
// 보드를 받고, dfs 함수로 들어간 뒤, 모든 출발점에서 내려가며 결과를 확인한 후 i-i 관계가 성립되면 지금까지 그었던 줄 개수를 결과값으로 반환 - 그은 개수가 3을 넘어선다면 탐색 중단
// 그런데 그을 수 있는 경우의 수가 최대 300가지인데, 300^3의 경우 2700만이 되어 제한 시간 내에 처리 불가능 - 가지치기 필요
// 1. 이미 값이 정해진 경우 이어지는 dfs 함수에서 더 탐색하지 않고 바로 반환하도록 설정
// 다만 이렇게만 두면 최단거리를 찾지 못함 - bfs가 아니라서 처음에 발견한 경로가 최단 경로임을 보장하지 않음
// 2. 사전에 그을 가로줄 수를 정하고 탐색 돌입 - 0~3 순서대로 dfs 함수에 처음 진입하고, 주어진 줄 수를 모두 그으면 결과 확인하고 성공하면 해당 줄 수를 결과값으로
// 이렇게 하면 1. 가지치기를 수행할 수 있지만, 2700만 탐색에 대한 위험성이 남아있음
// 3. 줄을 추가로 긋는 과정(재귀 호출)에서 현재 그어진 가로줄 위치 위는 더 보지 않도록 설정 - 어차피 앞선 재귀 결과에서 다 봤으므로
// 그렇게 되면 같은 경우의 수를 중복해서 보지 않게 되므로 탐색 시간을 더 절약할 수 있음 - 그리고 그래야 통과됨