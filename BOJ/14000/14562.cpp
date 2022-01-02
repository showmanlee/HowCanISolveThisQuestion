// 태권왕
// https://www.acmicpc.net/problem/14562

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int tc = 0; tc < tt; tc++) {
		int s, t;
		cin >> s >> t;
		queue<prr> q;
		q.push({ {s, t}, 0 });
		while (!q.empty()) {
			int ps = q.front().first.first;
			int pt = q.front().first.second;
			int cnt = q.front().second;
			q.pop();
			if (ps == pt) {
				cout << cnt << '\n';
				break;
			}
			if (ps > pt)
				continue;
			q.push({ {ps * 2, pt + 3}, cnt + 1 });
			q.push({ {ps + 1, pt}, cnt + 1 });
		}
	}
}

// 현재 자신의 점수만큼 점수를 얻으면서 상대에게 3점을 주는 발차기 A와 패널티 없이 1점을 받는 발차기 B가 있다
// 두 사람의 점수(s < t)가 주어질 때, 두 사람의 점수가 같아지도록 하는 발차기의 최소 횟수는?

// s *= 2와 t += 3을 하는 A 발차기, a += 1을 하는 B 발차기 등 2가지 선택지가 있는 bfs
// 현재 s와 t의 상태, 그리고 발차기를 한 횟수를 큐에 넣고 돌리기 - visit 배열을 사용할 필요는 없음
// 만약 현재 s와 t가 같으면 현재 카운트를 출력하고, s > t라면 더 이상 같아지게 할 수 없으므로 다음 케이스를 고려하지 않음