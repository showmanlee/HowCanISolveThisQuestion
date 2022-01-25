// 돌 그룹
// https://www.acmicpc.net/problem/12886

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

struct node {
	int a, b, c;
	node(int A, int B, int C) {
		a = A;
		b = B;
		c = C;
	}

	bool operator<(const node& y) {
		if (a != y.a)
			return a < y.a;
		if (b != y.b)
			return b < y.b;
		return c < y.c;
	}
};

bool operator<(const node& x, const node& y) {
	if (x.a != y.a)
		return x.a < y.a;
	if (x.b != y.b)
		return x.b < y.b;
	return x.c < y.c;
}

void swapping(int& a, int& b, int& c) {
	if (a > b) {
		swap(a, b);
	}
	if (b > c) {
		swap(b, c);
	}
	if (a > b) {
		swap(a, b);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	if ((a + b + c) % 3 != 0) {
		cout << 0 << '\n';
		return 0;
	}
	map<node, bool> visit;
	swapping(a, b, c);
	visit[node(a, b, c)] = true;
	queue<node> q;
	q.push(node(a, b, c));
	int res = 0;
	while (!q.empty()) {
		int a_ = q.front().a;
		int b_ = q.front().b;
		int c_ = q.front().c;
		q.pop();
		if (a_ == b_ && b_ == c_) {
			res = 1;
			break;
		}
		if (a_ != b_) {
			int aa = a_;
			int bb = b_;
			int cc = c_;
			bb -= a_;
			aa += a_;
			swapping(aa, bb, cc);
			if (visit.count(node(aa, bb, cc)) == 0) {
				visit[node(aa, bb, cc)] = true;
				q.push(node(aa, bb, cc));
			}
		}
		if (a_ != c_) {
			int aa = a_;
			int bb = b_;
			int cc = c_;
			cc -= a_;
			aa += a_;
			swapping(aa, bb, cc);
			if (visit.count(node(aa, bb, cc)) == 0) {
				visit[node(aa, bb, cc)] = true;
				q.push(node(aa, bb, cc));
			}
		}
		if (b_ != c_) {
			int aa = a_;
			int bb = b_;
			int cc = c_;
			cc -= b_;
			bb += b_;
			swapping(aa, bb, cc);
			if (visit.count(node(aa, bb, cc)) == 0) {
				visit[node(aa, bb, cc)] = true;
				q.push(node(aa, bb, cc));
			}
		}
	}
	cout << res << '\n';
	return 0;
}

// 세 그룹의 돌들 중 크기가 다른 두 그룹을 골라 큰 쪽의 돌 중 작은 쪽의 돌만큼을 작은 쪽으로 옮기는 과정을 반복할 때, 세 그룹의 돌을 동일하게 만들 수 있는가?

// 세 그룹의 돌 수를 이용한 bfs - 확실한 건 a + b + c가 3의 배수가 아니면 무조건 실패라는 것
// 3의 배수라면 합이 1이 될 가능성이 있으니 접근 가능
// 언제나 a <= b <= c를 보장시키는 자료형을 하나 만들어 queue와 map(visit 대용)에 활용
// q.front()의 a, b, c가 모두 동일하다면 성공, 그렇지 않다면 a-b, a-c, b-c가 다른 경우 행동을 취한 후 queue에 넣기