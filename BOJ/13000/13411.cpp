// 하늘에서 정의가 빗발친다!
// https://www.acmicpc.net/problem/13411

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<double, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pr> v;
	for (int i = 1; i <= n; i++) {
		double a, b, c;
		cin >> a >> b >> c;
		v.push_back({sqrt((a * a) + (b * b)) / c, i});
	}
	sort(v.begin(), v.end());
	for (pr p : v) {
		cout << p.second << '\n';
	}
}

// 2차원 좌표에서의 점들의 위치와 점으로 이동하는 속도가 주어질 떄, 원점에서 점까지 도달하는 순서 구하기

// 원점에서 점 사이의 거리 / 속도를 구해서 정렬한다 - 동률이면 낮은 번호대로
// float로 두고 풀면 틀리니 주의