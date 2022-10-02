// 종이자르기
// https://www.acmicpc.net/problem/2628

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x, y, n;
	cin >> x >> y >> n;
	vector<int> v = {0, x};
	vector<int> h = {0, y};
	for (int i = 0; i < n; i++) {
		int d, b;
		cin >> d >> b;
		if (d == 0) {
			h.push_back(b);
		} else {
			v.push_back(b);
		}
	}
	sort(v.begin(), v.end());
	sort(h.begin(), h.end());
	int xx = 0, yy = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		xx = max(xx, v[i + 1] - v[i]);
	}
	for (int i = 0; i < h.size() - 1; i++) {
		yy = max(yy, h[i + 1] - h[i]);
	}
	int res = xx * yy;
	cout << res << '\n';
}

// 종이의 가로세로 길이와 자르는 방향+위치가 주어질 때, 만들어진 조각들 중 가장 넓은 조각은?

// 각 방향별로 0과 최대 길이를 미리 넣은 배열을 만든 후, 자르는 방향과 위치가 주어질 때마다 해당되는 배열에 삽입한다
// 이후 배열들을 정렬한 후, 각 방향의 지점 사이의 길이 중 가장 긴 길이들을 곱해 넓이를 만든다
// 자르는 방향에 주의 - 가로로 자를 경우 세로선을 가로질러 자른다