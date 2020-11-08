// 케빈 베이컨의 6단계 법칙
// https://www.acmicpc.net/problem/1389

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> relation(n + 1, vector<bool>(n + 1));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		relation[a][b] = true;
		relation[b][a] = true;
	}

	int mini = 1, minv = 2100000000;
	for (int i = 1; i <= n; i++) {
		vector<int> distance(n + 1, -1);
		queue<int> q;
		q.push(i);
		distance[i] = 0;
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			for (int j = 1; j <= n; j++)
				if (relation[p][j] && distance[j] == -1) {
					distance[j] = distance[p] + 1;
					q.push(j);
				}
		}
		int sum = 0;
		for (int j : distance)
			sum += j;
		if (sum < minv) {
			minv = sum;
			mini = i;
		}
	}
	cout << mini << '\n';
}

// 모든 사람들에 대해서 다른 사람들에 대한 BFS 거리의 합을 구하고 그 최소값을 가진 사람 번호 구하기
// 친구 관계가 중복해서 들어올 수 있음(특별한 가중은 없음) - 인접행렬으로 그래프 만들기
// BFS를 n번 돌려도 풀리긴 함