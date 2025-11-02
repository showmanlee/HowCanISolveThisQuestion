// 창하의 뉴스와미디어 이야기
// https://www.acmicpc.net/problem/34023

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<string, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pr> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), [](pr& a, pr& b) {
		return a.second > b.second;
	});
	vector<vector<string>> res(4, vector<string>(n / 4));
	for (int i = 0; i < n; i++) {
		res[i % 4][i / 4] = v[i].first;
	}
	for (int i = 0; i < 4; i++) {
		sort(res[i].begin(), res[i].end());
		cout << (i + 1);
		for (int j = 0; j < n / 4; j++) {
			cout << ' ' << res[i][j];
		}
		cout << '\n';
	}
}

// 네 팀에게 단어 난이도 최댓값 차이가 적어지도록 나누기