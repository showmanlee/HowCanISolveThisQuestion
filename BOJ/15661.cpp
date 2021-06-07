// 링크와 스타트
// https://www.acmicpc.net/problem/15661

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int res;
int board[21][21];
bool check[21];

void dfs(int idx, int cnt, int goal) {
	if (cnt == goal) {
		vector<int> a, b;
		for (int i = 0; i < n; i++) {
			if (check[i])
				a.push_back(i);
			else
				b.push_back(i);
		}
		int aa = 0, bb = 0;
		for (int i = 0; i < a.size() - 1; i++) {
			for (int j = i + 1; j < a.size(); j++)
				aa += board[a[i]][a[j]] + board[a[j]][a[i]];
		}
		for (int i = 0; i < b.size() - 1; i++) {
			for (int j = i + 1; j < b.size(); j++)
				bb += board[b[i]][b[j]] + board[b[j]][b[i]];
		}
		res = min(abs(aa - bb), res);
		return;
	}
	for (int i = idx; i < n; i++) {
		check[i] = true;
		dfs(i + 1, cnt + 1, goal);
		check[i] = false;
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	res = 987654321;
	for (int i = 2; i <= n / 2; i++)
		dfs(0, 0, i);
	cout << res << '\n';
}

// 두 사람이 같은 팀이 되었을 때 추가되는 능력치 목록이 주어질 때, n명을 인원 수가 서로 다를 수 있는 두 팀으로 나눌 때 생기는 두 팀간의 능력치 차의 최소는?

// 스타트와 링크의 변형 - 이제 양 팀 인원 수가 같지 않아도 되고, 전체 인원 수가 홀수일 수 있음
// 문제에서는 1명인 팀도 있어도 된다고 했지만, 이 경우 그 팀의 능력치는 무조건 0이 되기에 능력치 차가 최소가 될 수 없음 - 1:1인 상황도 없고, 두 사람간 능력치는 0이 아님
// 따라서 팀을 2:n-2~ n/2:n/2로 나누어 경우의 수를 체크해볼 수 있음 (~n-2:2는 2:n-2와 같은 케이스)
// 매 dfs 브포를 시작하기 전에 목표치를 정한 뒤, 목표치만큼의 인원을 뽑아 팀을 나눈다 - true vs false
// 팀을 모두 뽑으면 뽑은 팀원들의 능력치를 모두 구한 뒤, 두 팀의 차를 절댓값화하여 결과값을 갱신한다