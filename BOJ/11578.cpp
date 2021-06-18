// 팀원 모집
// https://www.acmicpc.net/problem/11578

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int quests[11];
vector<int> teammates[11];
int res;

void dfs(int idx, int left, int cnt) {
	if (left == 0) {
		res = min(res, cnt);
		return;
	}
	for (int i = idx; i <= m; i++) {
		bool used = false;
		for (int q : teammates[i]) {
			quests[q]++;
			if (quests[q] == 1) {
				used = true;
				left--;
			}
		}
		if (used)
			dfs(i + 1, left, cnt + 1);
		for (int q : teammates[i]) {
			quests[q]--;
			if (quests[q] == 0)
				left++;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int p;
		cin >> p;
		for (int j = 0; j < p; j++) {
			int t;
			cin >> t;
			teammates[i].push_back(t);
		}
	}
	res = 987654321;
	dfs(1, n, 0); 
	if (res == 987654321)
		res = -1;
	cout << res << '\n';
}

// 일부 문제를 풀 수 있는 팀원들이 주어질 때, 모든 문제를 풀기 위해 모아야 하는 팀원의 최소 숫자는?

// 브루트포스 방식으로 팀원을 골라 남은 문제가 없어지면 고른 팀원 수로 결과값 갱신하기
// 많은 팀원에 의해 중복되게 문제를 풀 수도 있으므로 푼 문제 카운터는 bool이 아닌 int로 구현
// 만약 문제 카운터를 체크하는 과정에서 문제를 처음 푸는 인원이 등장하면 해당 인물을 카운트하여 다음 인원 구하기
// 그렇지 않다면 카운터를 초기화하고 다음 팀원 선택