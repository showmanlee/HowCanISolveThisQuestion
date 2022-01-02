// 회의실배정
// https://www.acmicpc.net/problem/1931

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main(void) {
	int n;
	cin >> n;
	vector<pair<int, int>> tt;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		tt.push_back(make_pair(a, b));
	}
	sort(tt.begin(), tt.end(), compare);
	int res = 0, t = 0;
	for (int i = 0; i < n; i++) {
		if (t <= tt[i].first) {
			t = tt[i].second;
			res++;
		}
	}
	cout << res << '\n';
}

// 무조건 빨리 시작하는 회의를 먼저 넣는 것이 능사는 아님 - 빨리 시작하는 회의가 짧은 회의라는 것을 보장할 수 없기 때문
// 그 반대도 마찬가지
// 아이디어 - 반대로 일찍 끝나는 회의를 기준으로 정렬하면 되지 않을까?