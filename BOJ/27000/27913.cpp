// SciComLove (2023)
// https://www.acmicpc.net/problem/27913

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	vector<bool> v(n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (i % 10 == 0 || i % 10 == 3 || i % 10 == 6) {
			v[i] = true;
			cnt++;
		}
	}
	for (int t = 0; t < q; t++) {
		int p;
		cin >> p;
		p--;
		v[p] = !v[p];
		cnt += v[p] ? 1 : -1;
		cout << cnt << '\n';
	}
}

// SciComLove 글자를 총 N개 늘어놓은 후, x번째 글자의 대소문자를 전환하는 과정을 q번 반복할 때, 남는 대문자 개수 구하기

// 배열 형태로 대문자를 기억한 후, x가 주어질 때마다 카운트를 세며 전환한다
// 총 10글자 중 1, 4, 7번째 글자가 원래 대문자 - 인덱스 구조에서는 -1