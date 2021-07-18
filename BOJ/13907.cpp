// 세금
// https://www.acmicpc.net/problem/13907

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, pr> prr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k, s, d;
	cin >> n >> m >> k >> s >> d;
	vector<vector<pr>> board(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a].push_back({ b, c });
		board[b].push_back({ a, c });
	}
	vector<int> inc(k + 1);
	for (int i = 1; i <= k; i++)
		cin >> inc[i];
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1987654321));
	priority_queue<prr> pq;
	pq.push({ 0, {s, 0} });
	dist[s][0] = 0;
	while (!pq.empty()) {
		int len = -pq.top().first;
		int cur = pq.top().second.first;
		int cnt = pq.top().second.second;
		pq.pop();
		if (len > dist[cur][cnt] || cnt == n)
			continue;
		for (pr p : board[cur]) {
			int next = p.first;
			int nlen = p.second;
			if (dist[next][cnt + 1] > len + nlen) {
				dist[next][cnt + 1] = len + nlen;
				pq.push({ -dist[next][cnt + 1], {next, cnt + 1} });
			}
		}
	}
	int res = 1987654321;
	int resi = 0;
	for (int i = 0; i <= n; i++) {
		if (res > dist[d][i]) {
			res = dist[d][i];
			resi = i;
		}
	}
	vector<pr> candi;
	for (int i = 1; i <= resi; i++) {
		if (dist[d][i] != 1987654321)
			candi.push_back({ i, dist[d][i] });
	}
	long long add = 0;
	for (int i = 0; i <= k; i++) {
		long long ret = 98765432198765;
		add += inc[i];
		for (pr p : candi)
			ret = min(ret, p.second + add * p.first);
		cout << ret << '\n';
	}
}

// 통행료가 다른 양방향 도로로 이어진 n개의 도시에서 두 도시 사이를 이동하는데 k일간 모든 도로의 통행료가 동일하게 인상된다고 할 때, 인상 시점의 최단 경로 구하기

// 최단 경로니 다익스트라 기반 - 누적되는 인상값이 일정하지는 않음 
// 다만 확실한 것은 모든 도로에 동일한 인상값이 누적되므로 구성되는 도로의 수가 적은 길일 수록 유리함 - 다만 그런 길이 최단 경로임은 보장할 수 없음(예제)
// 따라서 이번에는 다익스트라를 돌리되, 'i번 지점으로 도로 j개로 구성된 최단 경로의 길이'표시하는 2차원 dist 배열로 결과를 나타내야 함
// 그리고 그 후보군들은 dist[d][j]가 되겠지

// 보드를 받고, 각 날짜마다의 인상값을 받은 뒤, 다익스트라를 돌린다
// dist의 각 축 사이즈는 모두 n + 1 - 일부러 돌아가지 않는 한(어차피 불가능), 거쳐야 하는 최대 도로 수는 n - 1개임
// 이렇게 등장 도로 수별 dist를 뽑아낸 뒤, 해당 dist[d]들 중에서 가장 작은 값(최단 거리)과 그 위치를 찾는다
// 이후 그 위치까지의 dist[d] 중 갱신된 값들을 모두 별도의 후보 배열에 담는다 - 그 이상의 도로를 가지는 값들은 '최단 거리'보다 짧아질 수 없음
// 마지막으로 날짜를 돌리면서 후보 값들에 누적값을 더한 값들의 최솟값을 찾아 출력들하기