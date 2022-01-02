// 두 스티커
// https://www.acmicpc.net/problem/16937

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int h, w, n;
	cin >> h >> w >> n;
	vector<pr> stickers(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		stickers[i] = { a, b };
	}
	int res = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int x1 = stickers[i].first;
			int y1 = stickers[i].second;
			int x2 = stickers[j].first;
			int y2 = stickers[j].second;
			int p = (x1 * y1 + x2 * y2);
			bool pass = false;
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					if (x1 + x2 <= h && max(y1, y2) <= w) {
						pass = true;
					}
					if (max(x1, x2) <= h && y1 + y2 <= w) {
						pass = true;
					}
					swap(x2, y2);
				}
				swap(x1, y1);
			}
			if (pass) {
				res = max(res, p);
			}
		}
	}
	cout << res << '\n';
}

// h*w 보드에 크기가 다른 직사각형 모양의 스티커 n개 중 2개를 보드에 벗어나지 않게 붙일 때, 붙일 수 있는 최대 넓이는?

// 스티커 개수가 100개까지 주어지므로 브포로 접근 가능
// 스티커가 차지하는 공간 넓이를 줄이기 위해서는 두 스티커를 접하게 붙여야 한다
// 그리고 이는 x축끼리 or y축끼리 접하게 할 수 있다
// 이를 두 스티커의 모든 회전 케이스에 적용한다 - x/y축을 뒤집는 건 swap으로 구현
// 이렇게 만든 스티커 전체 x/y 길이가 보드 안에 들어온다면 두 스티커 넓이의 합으로 결과 갱신