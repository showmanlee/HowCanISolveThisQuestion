// 첫 번째 문제는 정말 쉬운 문제일까?
// https://www.acmicpc.net/problem/34071

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	int minn = 987654321, maxx = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		minn = min(v[i], minn);
		maxx = max(v[i], maxx);
	}
	if (v[0] == minn) {
		cout << "ez";
	} else if (v[0] == maxx) {
		cout << "hard";
	} else {
		cout << "?";
	}
	cout << '\n';
}

// 주어진 문자열들을 주어진 범위 순서대로 출력하기