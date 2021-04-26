// 퍼즐
// https://www.acmicpc.net/problem/1525

#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	map<string, int> visit;
	string input;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int p;
			cin >> p;
			input += to_string(p);
		}
	}
	queue<string> q;
	visit[input] = 0;
	q.push(input);
	while (!q.empty()) {
		string p = q.front();
		q.pop();
		if (p == "123456780")
			break;
		int d = p.find('0');
		int x = d / 3;
		int y = d % 3;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= 3 || yy >= 3)
				continue;
			string pp = p;
			swap(pp[x * 3 + y], pp[xx * 3 + yy]);
			if (visit.count(pp) == 0) {
				visit[pp] = visit[p] + 1;
				q.push(pp);
			}
		}
	}
	if (visit.count("123456780") == 0)
		visit["123456780"] = -1;
	cout << visit["123456780"] << '\n';
}

// 주어진 3*3 슬라이딩 퍼즐을 맞출 수 있는가? 있다면 최소 얼마나 걸리는가?
// 결국 최소 거리를 알아봐야 하니 bfs로 접근 - 보드는 문자 9개의 문자열로 치환하면 됨
// 큐 안에서 0의 위치(p.find)를 3*3 좌표계로 치환한 후, 0 주변의 블록과 서로 위치를 바꿔서 큐에 넣어 탐색하면 됨
// 그런데 이번 문제는 메모리 제한이 꽤나 큼 - 큐에 pair를 받게 하지 말고 visit에 직접 기록하게 하여 메모리 절약
// visit 역시 일반 배열이 아닌 map으로 만들어 경제적으로 탐색할 수 있게
// map.count(key)는 해당 키를 가진 value가 몇 개 있는지를 나타내는 함수 - 만약 이게 0이면 아직 탐색되지 않았다는 뜻으로 보고 탐색 가능

// BOJ 700문제 돌파! - 플레권으로 들어가기 전에 약점(dp, 그리디 등)을 푸는 것도 중요하다는 걸 명심할 것