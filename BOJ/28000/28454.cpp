// Gift Expire Date
// https://www.acmicpc.net/problem/28454

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string ss;
	cin >> ss;
	int yy = stoi(ss.substr(0, 4));
	int mm = stoi(ss.substr(5, 2));
	int dd = stoi(ss.substr(8, 2));
	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int y = stoi(s.substr(0, 4));
		int m = stoi(s.substr(5, 2));
		int d = stoi(s.substr(8, 2));
		bool r = true;
		if (y == yy) {
			if (m == mm) {
				if (d < dd) {
					r = false;
				}
			} else if (m < mm) {
				r = false;
			}
		} else if (y < yy) {
			r = false;
		}
		res += (r ? 1 : 0);
	}
	cout << res << '\n';
}

// 주어진 날짜보다 미래의 날짜 개수 구하기