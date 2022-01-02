// 한윤정이 이탈리아에 가서 아이스크림을 사먹는데
// https://www.acmicpc.net/problem/2422

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<bool>> no(n + 1, vector<bool>(n + 1));
	for (int k = 0; k < m; k++) {
		int a, b;
		cin >> a >> b;
		no[a][b] = no[b][a] = true;
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (no[i][j] || no[j][k] || no[k][i])
					continue;
				res++;
			}
		}
	}
	cout << res << '\n';
}

// 세 가지 아이스크림을 섞어먹으려고 하는 상황에서 섞어먹으면 안 되는 아이스크림의 쌍이 주어질 때, 먹을 수 있는 방법의 수는?
// 200^3이니 브루트포스로 접근 가능
// 2차원 배열에 못 섞어먹는 쌍을 기록하고, 3차원 for를 오름차순으로 돌리며 못 먹는 쌍이 나오지 않으면 결과값에 누적하기