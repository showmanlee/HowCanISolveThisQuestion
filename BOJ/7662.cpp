// 이중 우선순위 큐
// https://www.acmicpc.net/problem/7662

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		priority_queue<pr> max;
		priority_queue<pr, vector<pr>, greater<pr>> min;
		vector<bool> visit(1000001);
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			char op;
			int num;
			cin >> op >> num;
			if (op == 'I') {
				max.push(make_pair(num, i));
				min.push(make_pair(num, i));
				visit[i] = true;
			}
			else {
				if (num == -1) {
					while (!min.empty() && !visit[min.top().second])
						min.pop();
					if (!min.empty()) {
						visit[min.top().second] = false;
						min.pop();
					}
				}
				else {
					while (!max.empty() && !visit[max.top().second])
						max.pop();
					if (!max.empty()) {
						visit[max.top().second] = false;
						max.pop();
					}
				}
			}
		}
		while (!min.empty() && !visit[min.top().second])
			min.pop();
		while (!max.empty() && !visit[max.top().second])
			max.pop();

		if (min.empty() && max.empty())
			cout << "EMPTY" << '\n';
		else
			cout << max.top().first << ' ' << min.top().first << '\n';
	}
}

// 새로운 자료구조를 만들지 않아도 됨 - 물론 만들면 좋겠지만
// 1. 두 개의 priority_queue를 사용하기(이 경우 pair를 통해 인덱스 단위로 visit 배열을 활용해 두 힙을 관리해야 함)
// 2. deque를 이용해 삽입 시마다 정렬을 해 앞뒤로 넣고 빼기(매번 정렬하므로 느림)
// Programmers 버전은 2를, 여기선 1을 합니다
// visit 배열은 인덱스 별로 저장을 해서 이미 빠진 숫자가 다른 큐 안에 계속 있는지를 확인
// 그리고 pair같은 건 typedef같은 걸로 줄여서 사용할 수 있음