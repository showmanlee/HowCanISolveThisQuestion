// 88888
// https://www.acmicpc.net/problem/33756

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		long long n;
		cin >> n;
		bool res = true;
		if (n % 8 != 0) {
			res = false;
		} else {
			n /= 8;
			string a = to_string(n);
			string b = a;
			sort(b.begin(), b.end());
			if (a != b) {
				res = false;
			} else if (b.back() == '9') {
				res = false;
			}
		}
		cout << (res ? "Yes" : "No") << '\n';
	}
}

// 주어진 수가 8로만 구성된 자연수의 합으로 만들 수 있는지 구하기