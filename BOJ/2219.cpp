// 보안 시스템 설치
// https://www.acmicpc.net/problem/2219

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> connect(n + 1, vector<int>(n + 1, 987654));
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		connect[a][b] = c;
		connect[b][a] = c;
	}
	for (int i = 1; i <= n; i++)
		connect[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (connect[i][j] > connect[i][k] + connect[k][j])
					connect[i][j] = connect[i][k] + connect[k][j];
			}
		}
	}
	int res = -1, num = 987654321;
	for (int i = 1; i <= n; i++) {
		int p = 0;
		for (int j = 1; j <= n; j++)
			p += connect[i][j];
		if (num > p) {
			num = p;
			res = i;
		}
	}
	cout << res << '\n';
}

// 전송 시간이 회선마다 다른 양방향 컴퓨터 네트워크가 주어졌을 때, 가장 빨리 보안 패킷을 모든 컴퓨터에 보낼 수 있는 컴퓨터의 번호는?

// 최대한 컴퓨터와 네트워크로 연결되어 있고, 자신과 다른 컴퓨터들의 연결 속도의 합이 가장 낮은 컴퓨터를 찾아라 - 플로이드 활용
// 플로이드로 모든 컴퓨터에 대한 최소 거리를 찾은 뒤, 각 컴퓨터에 대해 다른 컴퓨터들과의 최소 거리의 합을 구해 그 값이 가장 작은 컴퓨터가 답
// 이를 위해 최소 거리 배열의 초기값을 매우 큰 값으로 잡아주기 - 모든 컴퓨터가 연결되면 저 값보다 낮음이 보장됨