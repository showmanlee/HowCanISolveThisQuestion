// LCS
// https://www.acmicpc.net/problem/9251

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;
    vector<vector<int>> v(1001, vector<int>(1001));

	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (b[j - 1] == a[i - 1]) {
				v[i][j] = v[i - 1][j - 1] + 1;
			} else {
				v[i][j] = max(v[i - 1][j], v[i][j - 1]);
			}
		}
	}
	cout << v[a.length()][b.length()] << '\n';
}

// 두 문자열의 최장 공통 부분 수열 구하기