// 물통
// https://www.acmicpc.net/problem/14867

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	pr init, dest;
	cin >> init.first >> init.second >> dest.first >> dest.second;
	map<pr, int> visit;
	int res = -1;
	queue<pr> q;
	q.push({ 0, 0 });
	visit[{0, 0}] = 1;
	while (!q.empty()) {
		pr p = q.front();
		q.pop();
		if (p == dest) {
			res = visit[p] - 1;
			break;
		}
		pr pp;
		pp = { init.first, p.second };
		if (visit.count(pp) == 0) {
			visit[pp] = visit[p] + 1;
			q.push(pp);
		}
		pp = { p.first, init.second };
		if (visit.count(pp) == 0) {
			visit[pp] = visit[p] + 1;
			q.push(pp);
		}
		pp = { 0, p.second };
		if (visit.count(pp) == 0) {
			visit[pp] = visit[p] + 1;
			q.push(pp);
		}
		pp = { p.first, 0 };
		if (visit.count(pp) == 0) {
			visit[pp] = visit[p] + 1;
			q.push(pp);
		}
		if (p.first > init.second - p.second)
			pp = { p.first + p.second - init.second, init.second };
		else
			pp = { 0, p.first + p.second };
		if (visit.count(pp) == 0) {
			visit[pp] = visit[p] + 1;
			q.push(pp);
		}
		if (p.second > init.first - p.first)
			pp = { init.first, p.first + p.second - init.first };
		else
			pp = { p.first + p.second, 0 };
		if (visit.count(pp) == 0) {
			visit[pp] = visit[p] + 1;
			q.push(pp);
		}
	}
	cout << res << '\n';
}

// 크기가 다른 두 개의 물통에 원하는 용량의 물을 채우기 위해 할 수 있는 행동으로 '가득 채우기, 모두 버리기, 다른 물통에 비거나 찰 때까지 붓기'를 할 수 있을 때, 원하는 상태로 만들 수 있는가? 있다면 최소 얼마나 걸리는가?

// pair를 이용한 bfs 활용하기 - 참고로 pair도 struct의 일종이라 == 연산이 됩니다
// visit는 map으로 구현 - 여기에 최초 도달 시점도 기록
// bfs 큐 안에서 할 수 있는 행동은 6개 - a/b 비우기, a/b 채우기, 다른 곳에 붓기
// 여기서 '다른 곳에 붓기'는 상황에 따라 채워지는 양이 다름 - 한 물통에 있는 물이 다른 물통에 남아있는 물 양보다 많은 경우
// 만약 그렇다면 다른 물통을 채우고 한 물통에는 물을 남기고, 그렇지 않다면 한 물통을 비우고 다른 물통에는 두 물통에 들어있던 물을 모두 담는다
// 이렇게 물통을 계속 조작하다 결과값에 도달하면 탐색 종료