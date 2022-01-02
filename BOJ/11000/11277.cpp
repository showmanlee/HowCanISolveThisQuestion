// 2-SAT - 1
// https://www.acmicpc.net/problem/11277

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
			break;
		}
	}
	cout << res << '\n';
}

// n개의 논리 변수가 두 개씩 or로 짝지어져 and로 연결된 식이 주어질 때, 논리 변수들의 값을 조정해 해당 식의 결과를 true로 만들 수 있는가?

// 사실 이 문제는 SCC 알고리즘이 도입되어야 하는 문제 - 하지만 n이 20까지인 만큼, 여기서는 브루트포스로도 접근할 수 있음(2^20)
// 최대 20개의 논리 변수를 순차적으로 조정하는 데는 비트마스크를 활용할 수 있음 - 0부터 2^n - 1까지
// 각 자리의 논리값을 or 식에 대입하여 초기값이 true인 결과 변수에 지속적으로 and 연산한 후, 끝까지 true로 남으면 2-SAT을 만족하는 것
// 그러니까, 모든 or 식에 대해 양측 변수 중 하나 이상이 true인 경우 해당 식이 성립하는 것 - SCC 적용 방식은 3번 문제에서...