// J박스
// https://www.acmicpc.net/problem/5354

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
					cout << '#';
				} else {
					cout << 'J';
				}
			}
			cout << '\n';
		}
		cout << '\n';
	}
}

// 길이가 n이고 테투리는 #, 내부는 J로 채워진 정사각형 그리기

// 그리면 됩니다 - 외곽에만 # 찍도록