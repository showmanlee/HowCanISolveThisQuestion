// 이진수 게임
// https://www.acmicpc.net/problem/18112

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string l, k;
	cin >> l >> k;
	int s = 0, e = 0;
	int d = 1;
	while (l.length() != 0) {
		s += d * (l.back() - '0');
		d *= 2;
		l.pop_back();
	}
	d = 1;
	while (k.length() != 0) {
		e += d * (k.back() - '0');
		d *= 2;
		k.pop_back();
	}
	vector<int> visit(1024, -1);
	queue<int> q;
	q.push(s);
	visit[s] = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (p == e)
			break;
		if (p < 1023 && visit[p + 1] == -1) {
			visit[p + 1] = visit[p] + 1;
			q.push(p + 1);
		}
		if (p > 0 && visit[p - 1] == -1) {
			visit[p - 1] = visit[p] + 1;
			q.push(p - 1);
		}
		for (int i = 0; i < 10; i++) {
			if ((1 << i) > p / 2)
				break;
			int pp1 = p & ~(1 << i);
			int pp2 = p | (1 << i);
			if (visit[pp1] == -1) {
				visit[pp1] = visit[p] + 1;
				q.push(pp1);
			}
			if (visit[pp2] == -1) {
				visit[pp2] = visit[p] + 1;
				q.push(pp2);
			}
		}
	}
	cout << visit[e] << '\n';
}

// 어떤 이진수의 맨 앞 자리를 제외한 숫자 하나를 뒤집거나, 1을 더하거나 빼서 목표 이진수로 바꾸는 최소 연산 수는?

// 이진수를 처리하는 bfs
// 이진수의 범위는 2^10까지 - 따라서 값이 나오는 범위가 0~1023 까지라고 생각할 수 있음
// 우선 출발/도착점을 문자열로 받은 뒤 정수형으로 변환하고, 출발점부터 bfs를 돌린다
// 이진수의 한 자리를 뒤집는 방법?
// - 우선 0부터 9까지 돌아가는 for 안에서 1 << i가 p / 2 이하인지 확인한다 - 맨 앞자리는 바꿀 수 없으므로 
// - 이후 해당 자리에 0을 넣는 경우( % ~(1 << i) ), 1을 넣는 경우( | (1 << i) )를 계산한 뒤 해당 수를 방문하지 않았다면 방문하기
// 이렇게 최단거리를 구해서 출력하기