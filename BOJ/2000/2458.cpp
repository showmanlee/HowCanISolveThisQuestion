// 키 순서
// https://www.acmicpc.net/problem/2458

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> rel(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		rel[a][b] = -1;
		rel[b][a] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (rel[i][j] == 0) {
					if (rel[i][k] == rel[k][j] && rel[i][k] != 0)
						rel[i][j] = rel[i][k];
				}
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++)
			if (rel[i][j] != 0)
				cnt++;
		if (cnt == n - 1)
			res++;
	}
	cout << res << '\n';
}

// 일부 사람들의 키 관계가 주어졌을 때, 자신의 키가 정확히 몇 번째로 큰지 알 수 있는 사람의 수는?

// 대소관계를 확인하기 위해서는 플로이드를 사용할 수 있음 - rel[i][k]와 rel[k][j]의 대소관계가 모두 확정되어 있고 서로 같다면 rel[i][j]를 정할 수 있다
// 그리고 자신이 정확히 몇 번째인지를 알려면 다른 모두와 비교한 결과를 알아야 한다 - 키가 같은 사람이 없기 때문에 동률이 나올 수 없음
// 즉, 플로이드를 돌린 후 자신이 아닌 사람들과의 대소관계가 모두 확정되었다면 그 사람은 자신의 순위를 알 수 있는 것

// 사람 간의 대소관계를 나타내는 2차원 배열을 만들고, 대소관계 입력을 받을 때 [a][b]는 -1, [b][a]는 1로 표신하여 대소관계를 기록한다
// 이후 해당 배열에 플로이드를 돌려 결정되지 않은 대소관계를 최대한 확정한다
// 마지막으로 모든 사람에 대해 모든 대소관계가 확정되었는지 확인하고, 그렇다면 결과값을 +1한다

// BOJ 750문제 돌파 - 1000문제를 찍더라도 실속있는 1000문제를 찍어보자