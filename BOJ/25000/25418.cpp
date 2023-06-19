// 정수 a를 k로 만들기
// https://www.acmicpc.net/problem/25418

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int a, k;
	cin >> a >> k;
	vector<int> visit(k + 1, -1);
	queue<int> q;
	q.push(a);
	visit[a] = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (p == k) {
			break;
		}
		if (p + 1 <= k && visit[p + 1] == -1) {
			visit[p + 1] = visit[p] + 1;
			q.push(p + 1);
		}
		if (p * 2 <= k && visit[p * 2] == -1) {
			visit[p * 2] = visit[p] + 1;
			q.push(p * 2);
		}
	}
	cout << visit[k] << '\n';
}

// +1, *2 연산을 이용하여 a에서 k를 만들 때, 필요한 최소 연산 횟수는?

// 단방햔 bfs - 증가하는 방향밖에 없으므로 배열 최댓값만 조심하며 작성하기