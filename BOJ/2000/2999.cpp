// 비밀 이메일
// https://www.acmicpc.net/problem/2999

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int n = s.length();
	int x = 0, y = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			int p = n / i;
			if (p < i) {
				break;
			}
			x = i;
			y = p;
		}
	}
	vector<vector<char>> v(x, vector<char>(y));
	int idx = 0;
	for (int j = 0; j < y; j++) {
		for (int i = 0; i < x; i++) {
			v[i][j] = s[idx];
			idx++;
		}
	}
	string res;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			res += v[i][j];
		}
	}
	cout << res << '\n';
}

// 문자열을 가로가 긴 형태의 2차원 배열에 열 순서로 넣은 후 행 순서로 다시 뽑아 문자열 만들기

// 시키는 대로 만들어봅시다