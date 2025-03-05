// 멘토와 멘티
// https://www.acmicpc.net/problem/26265

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<string, string> pr;

bool compare(pr& a, pr& b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pr> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
}

// 문자열쌍 배열을 앞줄은 오름차순, 뒷줄은 내림차순으로 출력하기