// 아스키 아트
// https://www.acmicpc.net/problem/17072

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	int n, m;
	vector<vector<char>> intensity;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		vector<char> v;
		for (int j = 0; j < m; j++) {
			int r, g, b;
			cin >> r >> g >> b;
			int p = r * 2126 + g * 7152 + b * 722;
			if (p < 510000)
				v.push_back('#');
			else if (p < 1020000)
				v.push_back('o');
			else if (p < 1530000)
				v.push_back('+');
			else if (p < 2040000)
				v.push_back('-');
			else
				v.push_back('.');
		}
		intensity.push_back(v);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << intensity[i][j];
		cout << endl;
	}
}