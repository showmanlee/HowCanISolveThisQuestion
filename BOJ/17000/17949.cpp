// Drop The Byte!
// https://www.acmicpc.net/problem/17949

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<unsigned long long> v(n);
	int idx = 0;
	for (int i = 0; i < n; i++) {
		string t, r;
		cin >> t;
		if (t == "char") {
			r = s.substr(idx, 2);
			idx += 2;
		} else if (t == "int") {
			r = s.substr(idx, 8);
			idx += 8;
		} else if (t == "long_long") {
			r = s.substr(idx, 16);
			idx += 16;
		}
		long long p = 1;
		reverse(r.begin(), r.end());
		for (int j = 0; j < r.length(); j++) {
			if (r[j] >= 'a' && r[j] <= 'f') {
				v[i] += (r[j] - 'a' + 10) * p;
			} else {
				v[i] += (r[j] - '0') * p;
			}
			p *= 16;
		}
	}
	for (long long i : v) {
		cout << i << ' ';
	}
	cout << '\n';
}

// 주어진 16진수를 자료형 길이대로 잘라서 정수로 변환하기