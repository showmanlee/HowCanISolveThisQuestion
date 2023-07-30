// Majestic 10
// https://www.acmicpc.net/problem/25893

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int res = 0;
		vector<int> v(3);
		for (int i = 0; i < 3; i++) {
			cin >> v[i];
			if (v[i] >= 10) {
				res++;
			}
		}
		cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
		if (res == 0) {
			cout << "zilch";
		} else if (res == 1) {
			cout << "double";
		} else if (res == 2) {
			cout << "double-double";
		} else if (res == 3) {
			cout << "triple-double";
		}
		cout << '\n';
		if (t != tt - 1) {
			cout << '\n';
		}
	}
}

// 주어진 3개의 수 중 10 이상인 수가 몇 개 있는지 출력하기
// 하면 됩니다... - 출력에만 유의하세요