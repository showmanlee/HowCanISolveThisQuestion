// DORO
// https://www.acmicpc.net/problem/34073

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i] += "DORO";
		if (i != n - 1) {
			v[i] += ' ';
		}
	}
	for (int i = 0; i < n; i++) {
		cout << v[i];
	}
	cout << '\n';
}

// 단어 끝마다 DORO 붙이기