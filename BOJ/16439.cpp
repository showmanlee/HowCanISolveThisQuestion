// 치킨치킨치킨
// https://www.acmicpc.net/problem/16439

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pref[31][31];
int n, m, res;
int selected[4];

void dfs(int idx) {
	if (idx == 3) {
		int p = 0;
		for (int i = 1; i <= n; i++)
			p += max(pref[i][selected[1]], max(pref[i][selected[2]], pref[i][selected[3]]));
		res = max(res, p);
		return;
	}
	for (int i = selected[idx] + 1; i <= m; i++) {
		selected[idx + 1] = i;
		dfs(idx + 1);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> pref[i][j];
	res = 0;
	dfs(0);
	cout << res << '\n';
}

// 각 치킨별 호감도가 다른 n명의 사람이 m종류의 치킨 중 3가지를 시키고, 개인의 최종 호감도는 시킨 치킨의 호감도의 최대일 때, 확보할 수 있는 호감도의 합의 최댓값은?

// 치킨 종류나 사람이나 최대 30 - 브루트포스로 처리 가능
// dfs로 중복 없이 3개의 치킨을 뽑고, 각 사람별 세 치킨의 호감도 중 최대를 뽑아 더한 후, 결과값에 갱신하기