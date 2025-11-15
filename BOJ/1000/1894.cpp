// 4번째 점
// https://www.acmicpc.net/problem/1894

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<double, double> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<pr> v(4);
	while (cin >> v[0].first >> v[0].second) {
		for (int i = 1; i < 4; i++) {
			cin >> v[i].first >> v[i].second;
		}
		pr a, b, c;
		if (v[0] == v[1]) {
			c = v[0];
			a = v[2];
			b = v[3];
		} else if (v[0] == v[2]) {
			c = v[0];
			a = v[1];
			b = v[3];			
		} else if (v[0] == v[3]) {
			c = v[0];
			a = v[1];
			b = v[2];
		} else if (v[1] == v[2]) {
			c = v[1];
			a = v[0];
			b = v[3];
		} else if (v[1] == v[3]) {
			c = v[1];
			a = v[0];
			b = v[2];
		} else if (v[2] == v[3]) {
			c = v[2];
			a = v[0];
			b = v[1];
		}
		pr res;
		res.first = c.first + (a.first - c.first) + (b.first - c.first);
		res.second = c.second + (a.second - c.second) + (b.second - c.second);

		cout << fixed;
    	cout.precision(3);
		cout << res.first << ' ' << res.second << '\n';
	}
}

// 평행사변형을 구성하는 맞닿은 두 선분이 주어질 때 두 선분에 포함되지 않는 점의 위치 구하기