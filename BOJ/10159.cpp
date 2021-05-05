// 저울
// https://www.acmicpc.net/problem/10159

#include <iostream>
#include <vector>
#include <algorithm>
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
	for (int i = 1; i <= n; i++) {
		int res = -1;
		for (int j = 1; j <= n; j++)
			if (rel[i][j] == 0)
				res++;
		cout << res << '\n';
	}
}

// 서로 다른 두 물건을 양팔저울로 잰 결과들이 있을 때, 이 정보들을 바탕으로 한 물건을 기준으로 대소관계를 예측할 수 없는 물건의 수는?

// 대소관계 판별을 위한 플로이드 사용 - rel[i][k] == rel[k][j] && rel[i][k] != 0일 때 rel[i][j]도 알 수 있다
// 여기서 rel[a][b] == -1이라면 a가 더 무겁고, 1이라면 b가 더 무거움을 의미
// 정보를 받은뒤 해당 정보를 바탕으로 플로이드를 돌려 대소관계를 확립시킨 후에도 대소관계가 0으로 남아있는 곳은 주어진 정보로 대소관계를 확립할 수 없는 곳임을 의미
// 따라서 각각의 물건(i)에 대해 rel[i][j] == 0인 수를 세면 결과가 된다
// 단, 여기서 rel[i][i]는 언제나 0일 수밖에 없으니 카운트를 -1부터 시작