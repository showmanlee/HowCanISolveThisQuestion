// 회장뽑기
// https://www.acmicpc.net/problem/2660

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, 987654321));
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1)
			break;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
	int res = 987654321;
	vector<int> candidates;
	for (int i = 1; i <= n; i++) {
		int score = 0;
		for (int j = 1; j <= n; j++)
			score = max(score, dist[i][j]);
		if (score < res) {
			res = score;
			candidates.clear();
		}
		if (score == res)
			candidates.push_back(i);
	}
	cout << res << ' ' << candidates.size() << '\n';
	for (int i : candidates)
		cout << i << ' ';
	cout << '\n';
}

// 모임에서 한 회원과 다른 회원에게 도달하기 위해 거쳐야 하는 친구 관계의 수의 최대를 그 회원의 '점수'라고 할 때, 가장 낮은 점수와 그 점수를 가진 회원 목록 출력하기
// '친구 관계'는 가중치 1짜리 양방향 간선이라고 볼 수 있음 - 기본적으로 전체 관계의 최소 거리를 봐야 하니 플로이드로 접근 가능
// 플로이드를 돌려 모든 관계의 거리를 측정한 후, 1번 회원부터 다른 회원과의 거리의 최대를 구한다
// 만약 구한 값으로 최소 점수가 갱신되어야 한다면, 최소 점수를 갱신하고 후보 vector를 초기화한다
// 만약 최소 점수가 구한 값과 같다면(또는 위의 과정 이후), 후보 vector에 해당 회원을 넣는다 - 이 과정에서 자동으로 오름차순 정렬
// 이렇게 구한 최소 점수와 후보의 수, 후보 내역을 출력하기