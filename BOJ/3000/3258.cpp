// 컴포트
// https://www.acmicpc.net/problem/3258

#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, z, m;
	cin >> n >> z >> m;
	z--;
	vector<bool> v(n);
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		p--;
		v[p] = true;
	}
	for (int i = 1; i <= n; i++) {
		int p = 0;
		vector<bool> visit(n);
		bool pass = false;
		while (!visit[p]) {
			if (v[p]) {
				break;
			}
			visit[p] = true;
			if (p == z) {
				pass = true;
				break;
			}
			p = (p + i) % n;
		}
		if (pass) {
			cout << i << '\n';
			break;
		}
	}
}

// n개 칸 중 m개의 장애물이 있는 원형 보드를 일정 간격으로 뛸 때, 장애물을 밟지 않고 z번 칸으로 이동하는 최소 간격 구하기