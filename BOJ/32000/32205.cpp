// 네모의 꿈
// https://www.acmicpc.net/problem/32205

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<bool> visit(1000001);
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			int p;
			cin >> p;
			if (visit[p]) {
				res = 1;
			}
			visit[p] = true;
		}
	}
	cout << res << '\n';
}

// ISBN에 빈 한 숫자 출력하기