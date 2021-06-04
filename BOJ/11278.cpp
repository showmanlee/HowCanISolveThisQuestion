// 2-SAT - 2
// https://www.acmicpc.net/problem/11278

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<pr> cnf(m);
	for (int i = 0; i < m; i++)
		cin >> cnf[i].first >> cnf[i].second;
	bool res = false;
	int resn = -1;
	for (int b = 0; b < pow(2, n); b++) {
		bool p = true;
		for (int i = 0; i < m; i++) {
			int x = abs(cnf[i].first) - 1, y = abs(cnf[i].second) - 1;
			bool xx = ((b >> x) % 2), yy = ((b >> y) % 2);
			if (cnf[i].first < 0)
				xx = !xx;
			if (cnf[i].second < 0)
				yy = !yy;
			bool t = xx || yy;
			p &= t;
		}
		if (p) {
			res = true;
			resn = b;
			break;
		}
	}
	cout << res << '\n';
	if (res) {
		for (int i = 0; i < n; i++)
			cout << (resn >> i) % 2 << ' ';
		cout << '\n';
	}
}

// n개의 논리 변수가 두 개씩 or로 짝지어져 and로 연결된 식이 주어질 때, 논리 변수들의 값을 조정해 해당 식의 결과를 true로 만들 수 있는가? 있다면 각 변수에 어떤 값을 줘야 하는가?

// 1번 문제와 마찬가지로 브루트포스로 값을 주고, 만약 통과되는 경우가 나왔다면 해당 값을 가져와 0부터 하나씩 출력하기
// 이게 SCC와 결합되면 어려워지는데 - 그런 문제는 4번에서...