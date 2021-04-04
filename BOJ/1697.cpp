// 숨바꼭질
// https://www.acmicpc.net/problem/1697

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	vector<int> visit(100001, -1);
	queue<int> q;
	q.push(n);
	visit[n] = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (p == k)
			break;
		if (p + 1 <= 100000 && visit[p + 1] == -1) {
			visit[p + 1] = visit[p] + 1;
			q.push(p + 1);
		}
		if (p - 1 >= 0 && visit[p - 1] == -1) {
			visit[p - 1] = visit[p] + 1;
			q.push(p - 1);
		}
		if (p * 2 <= 100000 && visit[p * 2] == -1) {
			visit[p * 2] = visit[p] + 1;
			q.push(p * 2);
		}
	}
	cout << visit[k] << '\n';
}

// DP같지만 BFS 문제 - 경로 변화 모형이 트리의 형태를 띈다
// 뻗을 수 있는 경로는 +1, -1, *2 - +1-1과 같은 방식으로 여러 번 밟을 수 있으니까 visit 배열 필요
// 최단 거리를 찾기 위해 K를 넘을 수 있으므로 visit 배열 크기는 반드시 100000 이상이어야 함