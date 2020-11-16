// 절댓값 힙
// https://www.acmicpc.net/problem/11286

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct cmp {
	bool operator()(int& a, int& b) {
		if (abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	priority_queue<int, vector<int>, cmp> pq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p == 0) {
			if (pq.empty())
				cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(p);
	}
}

// priority_queue<int, vector<int>, cmp> 식으로 커스텀 비교식을 이용한 우선순위 큐도 만들 수 있음
// 단, cmp는 struct이고, cmp는 bool operator()(int& a, int& b)을 가지고 있어야 한다.
// 최소 힙을 만들고 싶으면 >, 최대 힙을 만들고 싶으면 <
// 물론 커스텀 만들 필요 없이 절댓값과 본래값을 가진 pair 기반 힙을 만들어도 됨