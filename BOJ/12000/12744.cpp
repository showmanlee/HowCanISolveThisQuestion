// 팬케이크 쌓기
// https://www.acmicpc.net/problem/12744

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string beg;
	for (int i = 0; i < n * 2; i++)
		beg += " ";
	for (int i = 0; i < n; i++)
		cin >> beg[i] >> beg[n + i];
	string dest;
	for (int i = 1; i <= n; i++)
		dest += to_string(i);
	for (int i = 1; i <= n; i++)
		dest += "+";

	map<string, int> visit;
	visit[beg] = 0;
	queue<string> q;
	q.push(beg);
	int res = -1;
	while (!q.empty()) {
		string s = q.front();
		q.pop();
		if (s == dest) {
			res = visit[s];
			break;
		}
		for (int i = 1; i <= n; i++) {
			string t = s;
			for (int j = 0; j < i; j++)
				t[n + j] = (t[n + j] == '+' ? '-' : '+');
			for (int j = 0; j < i / 2; j++) {
				swap(t[j], t[i - j - 1]);
				swap(t[n + j], t[n + i - j - 1]);
			}
			if (visit.count(t) == 0) {
				visit[t] = visit[s] + 1;
				q.push(t);
			}
		}
	}
	cout << res << '\n';
}

// 크기가 다른 팬케이크가 쌓인 더미가 있다
// 제일 위부터 여러 개의 팬케이크를 연속으로 골라 통째로 뒤집는 행동을 할 수 있을 때, 팬케이크 더미가 크기 순서대로 정방향으로 쌓인 경우를 만드는 최소 행동 횟수는?

// 팬케이크의 최대 개수가 6이라 bfs로 접근 가능
// 팬케이크 크기와 방향 현황을 string으로 기록하기 - visit 배열은 map으로 관리
// (n == 5일 때) 목표는 문자열을 "12345+++++"로 만드는 것 - 앞자리는 팬케이크의 크기, 뒷자리는 해당 팬케이크의 방향
// 큐 안에서 1부터 n까지 순회하며 해당되는 팬케이크를 모두 뒤집은(+ <-> -) 후, 위치도 바꿔준다
// 그러다가 목표에 도달하면 경과된 시간 출력하기