// 대지
// https://www.acmicpc.net/problem/9063

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int minx = 10001;
	int maxx = -10001;
	int miny = 10001;
	int maxy = -10001;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		minx = min(minx, x);
		miny = min(miny, y);
		maxx = max(maxx, x);
		maxy = max(maxy, y);
	}
	cout << ((maxx - minx) * (maxy - miny)) << '\n';
}

// 주어진 2차원 좌표를 모두 덮는 좌표축에 평행한 직사각형의 최소 넓이는?

// 주어진 좌표들 중 최솟값과 최댓값을 구한 뒤, 그 좌표들을 대각선으로 하는 직사각형의 넓이를 구한다

// solved.ac 100일 스트릭 돌파!(2021.07.21~)
// 빨리 표지 친구에게 샌드위치를 물립시다