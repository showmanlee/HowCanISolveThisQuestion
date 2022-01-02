// 돌다리
// https://www.acmicpc.net/problem/12761

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, n, m;
	cin >> a >> b >> n >> m;
	vector<int> visit(100001, -1);
	visit[n] = 0;
	queue<int> q;
	q.push(n);
	vector<int> d{-b, -a, -1, 1, a, b};
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (p == m)
			break;
		for (int i : d) {
			int pp = p + i;
			if (pp < 0 || pp > 100000)
				continue;
			if (visit[pp] == -1) {
				visit[pp] = visit[p] + 1;
				q.push(pp);
			}
		}
		if (p * a <= 100000 && visit[p * a] == -1) {
			visit[p * a] = visit[p] + 1;
			q.push(p * a);
		}
		if (p * b <= 100000 && visit[p * b] == -1) {
			visit[p * b] = visit[p] + 1;
			q.push(p * b);
		}
	}
	cout << visit[m] << '\n';
}

// 0~100000까지의 번호가 붙은 돌다리의 어느 출발점에서 도착점까지 이동하기 위해 좌우 1칸, a칸, b칸 이동, 또는 현재 번호에서 *a, *b번 돌다리로 이동할 수 있을 때, 최단 거리 출력하기

// 0~100000까지의 1차원 보드 안에서 펼쳐지는 bfs - 이동 방식이 다양하긴 하지만 원론적으로는 같은 bfs
// 1, a, b칸 이동의 경우 d 배열을 만들어서 배열 순회로 각자의 위치에 이동할 수 있게 하고, *a, *b칸 이동은 상황마다 목적지가 다르니 별도로 계산하기 - 곱하기 이동은 우측으로만 이동함에 주의
// 이렇게 움직이면서 visit 배열 안에는 해당 지점에 최초로 도달한(= 최소) 이동 횟수를 기록, m에 도달했다면 탐색 종류 후 출력