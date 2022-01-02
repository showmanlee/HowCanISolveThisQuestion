// 소수 경로
// https://www.acmicpc.net/problem/1963

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> prime(10000, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= 100; i++) {
		if (prime[i]) {
			for (int j = i * 2; j < 10000; j += i)
				prime[j] = false;
		}
	}
	for (int i = 0; i < 1000; i++)
		prime[i] = false;
	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int a, b;
		cin >> a >> b;
		int res = -1;
		vector<int> visit(10000, -1);
		visit[a] = 0;
		queue<int> q;
		q.push(a);
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			if (p == b) {
				res = visit[p];
				break;
			}
			for (int i = 0; i < 4; i++) {
				string s = to_string(p);
				for (int j = 0; j < 10; j++) {
					s[i] = '0' + j;
					int pp = stoi(s);
					if (prime[pp] && visit[pp] == -1) {
						visit[pp] = visit[p] + 1;
						q.push(pp);
					}
				}
			}
		}
		if (res == -1)
			cout << "Impossible" << '\n';
		else
			cout << res << '\n';
	}
}

// 4자리 소수를 한 번에 한 자리씩만 바꿔서 소수임을 유지하면서 다른 소수로 바꿀 때, 걸리는 과정 수는?
// 소수와 결합한 bfs 최단경로 문제

// 에라토스테네스로 4자리 소수를 모두 구하고, 앞자리가 0인 경우는 접근할 수 없으므로 0~999까지의 소수를 모두 지워준다
// 이후 큐 안에서 한 자리씩 바꿔가며 만든 수가 소수면서 방문하지 않은 곳이라면 큐에 삽입
// 이후 도착지에 도달하면 측정한 길이 출력하기