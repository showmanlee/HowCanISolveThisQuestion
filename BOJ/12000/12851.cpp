// 숨바꼭질 2
// https://www.acmicpc.net/problem/12851

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	vector<int> visit(100001, 987654321);
	queue<int> q;
	q.push(n);
	visit[n] = 0;
	int res = 987654321, count = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (p == k) {
			if (visit[k] < res) {
				res = visit[k];
				count = 1;
			}
			else if (visit[k] == res)
				count++;
			continue;
		}
		if (p + 1 <= 100000 && visit[p + 1] >= visit[p] + 1) {
			visit[p + 1] = visit[p] + 1;
			q.push(p + 1);
		}
		if (p - 1 >= 0 && visit[p - 1] >= visit[p] + 1) {
			visit[p - 1] = visit[p] + 1;
			q.push(p - 1);
		}
		if (p * 2 <= 100000 && visit[p * 2] >= visit[p] + 1) {
			visit[p * 2] = visit[p] + 1;
			q.push(p * 2);
		}
	}
	cout << res << '\n' << count << '\n';
}

// 0~100000까지의 선분 상에 나는 n에 있고, 목표가 k에 있다. 목표로 이동하기 위해 +1, -1, *2로 이동할 수 있을 때, 잡을 수 있는 최소 시간과 그 경로의 수는?
// 1697 숨바꼭질과 달리 이젠 경로 수까지 판단해야 한다 - k에 도달하더라도 bfs 순회 자체를 멈추지 말아야 함
// 현재까지의 최단 시간과 경로 수를 기록하는 변수를 생성, k까지 도달한 현재 기록이 최단 시간과 같으면 경로 수를 추가하고, 더 적다면 초기화해야 함
// visit 갱신 및 큐 삽입 조건 역시 visit가 -1일 경우에서 이동할 곳에 visit가 현재 visit + 1보다 큰 경우로 바꿔줘야 함