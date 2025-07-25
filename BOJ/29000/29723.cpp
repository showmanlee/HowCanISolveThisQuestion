// 브실이의 입시전략
// https://www.acmicpc.net/problem/29723

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	map<string, int> points;
	vector<string> dict;
	for (int i = 0; i < n; i++) {
		string s;
		int p;
		cin >> s >> p;
		points[s] = p;
		dict.push_back(s);
	}
	map<string, int> visit;
	for (int i = 0; i < k; i++) {
		string s;
		cin >> s;
		visit[s] = true;
	}
	int b = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (visit[dict[i]]) {
			b += points[dict[i]];
		} else {
			v.push_back(points[dict[i]]);
		}
	}
	sort(v.begin(), v.end());
	int maxx = 0, minn = 0;
	for (int i = 0; i < m - k; i++) {
		minn += v[i];
		maxx += v[n - k - 1 - i];
	}
	cout << (minn + b) << ' ' << (maxx + b) << '\n';
}

// 주어진 과목과 점수에 대해 공개된 k개의 과목 외 합쳐서 m개의 과목을 뽑을 때 최소 점수와 최대 점수 구하기