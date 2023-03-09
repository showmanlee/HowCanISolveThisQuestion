// 짐 챙기는 숌
// https://www.acmicpc.net/problem/1817

#include <iostream>
#include <vector>
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
	int res = 0, cur = 0;
	for (int i = 0; i < n; i++) {
		if (cur + v[i] > m) {
			res++;
			cur = v[i];
		} else {
			cur += v[i];
		}
	}
	if (cur != 0) {
		res++;
	}
	cout << res << '\n';
}

// 상자 하나의 용량과 각 책의 무게가 넣는 순서대로 주어질 떄, 필요한 상자의 개수 구하기

// 책들을 순서대로 넣어보자 - 그렇게 넣다가 넘치는 순간이 되면 새 상자에다 넣는 거지
// 이렇게 사용한 상자의 수를 세서 출력한다