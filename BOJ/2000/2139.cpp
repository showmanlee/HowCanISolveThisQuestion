// 나는 너가 살아온 날을 알고 있다
// https://www.acmicpc.net/problem/2139

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int d, m, y;
		cin >> d >> m >> y;
		if (d == 0) {
			break;
		}
		int f = ((y % 4 == 0) ? ((y % 400 == 0) ? 1 : (y % 100 != 0) ? 1 : 0) : 0);
		int mm = 1, dd = 1;
		int res = 1;
		while (mm != m || dd != d) {
			dd++;
			res++;
			if (mm == 2) {
				if (dd > 28 + f) {
					dd = 1;
					mm++;
				}
			} else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
				if (dd > 30) {
					dd = 1;
					mm++;
				}
			} else {
				if (dd > 31) {
					dd = 1;
					mm++;
				}
			}
		}
		cout << res << '\n';
	}
}

// 주어진 날짜가 1월 1일부터 며칠째인지 구하기