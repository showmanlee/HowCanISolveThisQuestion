// snails
// https://www.acmicpc.net/problem/34434

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cin.ignore();
	string s;
	for (int t = 0; t < n; t++) {
		getline(cin, s);
		stringstream ss(s);
		vector<long long> v(32769);
		long long p;
		int idx = 0;
		while (ss >> p) {
			v[idx] = p;
			idx++;
		}
		bool pass = true;
		for (int i = 0; i < min(idx, 4); i++) {
			if (v[i] != i) {
				pass = false;
				break;
			}
		}
		if (pass) {
			for (int i = 4; i < idx; i++) {
				if (v[i] != v[i - 1] + v[i - 2] + v[i - 3] + v[i - 4]) {
					pass = false;
					break;
				}
			}
		}
		cout << (pass ? "NAUTILUS" : "SNAIL") << '\n';
	}
}

// 주어진 수열이 노틸러스꼴인지 구하기