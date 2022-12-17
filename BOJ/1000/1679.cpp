// 숫자놀이
// https://www.acmicpc.net/problem/1679

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
	vector<int> pool(n);
	for (int i = 0; i < n; i++) {
		cin >> pool[i];
	}
	int k;
	cin >> k;
	queue<pr> q;
	vector<bool> visit(50001);
	for (int i : pool) {
		q.push({i, 1});
		visit[i] = true;
	}
	while (!q.empty()) {
		int p = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cnt < k) {
			for (int i : pool) {
				int pp = p + i;
				if (!visit[pp]) {
					visit[pp] = true;
					q.push({pp, cnt + 1});
				}
			}
		}
	}
	for (int i = 1; i <= 50000; i++) {
		if (!visit[i]) {
			cout << (i % 2 == 0 ? "holsoon" : "jjaksoon") << " win at " << i << '\n';
			break;
		}
	}
}

// 주어진 수들을 최대 k번 더해서 1부터 하나씩 높은 수를 만들 때, 게임이 끊기는 시점과 홀짝 구하기

// bfs - 최대 깊이가 k인 bfs로 가능한 모든 결과의 수 확인하기
// 사용하는 수가 1000 이하이고 최대 깊이가 50이므로 1000*50 = 50000을 visit 배열 크기로 잡아준다