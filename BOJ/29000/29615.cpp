// 알파빌과 베타빌
// https://www.acmicpc.net/problem/29615

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<bool> target(n + 1);
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		target[p] = true;
	}
	int res = 0;
	for (int i = 0; i < m; i++) {
		if (!target[v[i]]) {
			res++;
		}
	}
	cout << res << '\n';
}

// 주어진 소문자 문자열에서 같은 문자열을 한 글자씩 뒤로 가게 해서 n번 반복할 때 나오는 r의 개수 구하기