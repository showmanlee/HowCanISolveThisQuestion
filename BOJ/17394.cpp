// 핑거 스냅
// https://www.acmicpc.net/problem/17394

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> prime(100001, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sqrt(100000); i++) {
		if (prime[i]) {
			for (int j = i * 2; j <= 100000; j += i)
				prime[j] = false;
		}
	}
	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n, a, b;
		cin >> n >> a >> b;
		bool valid = false;
		for (int i = a; i <= b; i++) {
			if (prime[i]) {
				valid = true;
			}
		}
		if (!valid) {
			cout << -1 << '\n';
			continue;
		}
		vector<bool> visit(1000001);
		queue<pr> q;
		q.push({ n, 0 });
		visit[n] = true;
		int res = -1;
		while (!q.empty()) {
			int p = q.front().first;
			int time = q.front().second;
			q.pop();
			if (p >= a && p <= b && prime[p]) {
				res = time;
				break;
			}
			visit[p] = true;
			if (!visit[p / 2])
				q.push({ p / 2, time + 1 });
			if (!visit[p / 3])
				q.push({ p / 3, time + 1 });
			if (p + 1 <= 1000000 && !visit[p + 1])
				q.push({ p + 1, time + 1 });
			if (p - 1 >= 0 && !visit[p - 1])
				q.push({ p - 1, time + 1 });
		}
		cout << res << '\n';
	}
}

// n을 / 3, / 2, + 1, - 1 연산을 하여 a 이상 b 이하의 소수로 만들 수 있는 연산의 최소 횟수는?
// 계산형 bfs 문제 - 다만 소수 판정을 곁들인
// 소수 리스트를 미리 만들어놓고 계산 범위에 맞춰 bfs를 돌리면 가능
// 다만 a와 b 사이에 소수가 없다면 판정 자체가 불가능하므로, bfs 개시 전에 해당 영역에 소수가 없는지 확인해야 함

// 소수 판정은 에라토스테네스의 체를 사용하세요 - 소수의 배수를 모두 지워서 남는 수가 소수
// 처음에 모두 true로 초기화된 소수임을 표시하는 배열을 이용해 2차원 for를 돌리면서, 소수인 수를 발견했다면 해당 수의 배수를 모두 false로 만들기